#include "beergameserver.h"

#include <iostream>

#include <QJsonDocument>

BeerGameServer::BeerGameServer(QObject *parent) :
    QTcpServer(parent)
{
    std::cout << "Starting server" << std::endl;
}

void BeerGameServer::incomingConnection(qintptr socketDescriptor) {
    PlayerInterfaceServer* playerInterfaceServer = new PlayerInterfaceServer(nullptr);
    // try to bind the socket to the interface
    if(!playerInterfaceServer->setSocketDescriptor(socketDescriptor)) {
        playerInterfaceServer->deleteLater();
        return;
    }

    connect(playerInterfaceServer, &PlayerInterfaceServer::disconnectedFromPlayer,
            this, std::bind(&BeerGameServer::playerDisconnected, this, playerInterfaceServer));
    connect(playerInterfaceServer, &PlayerInterfaceServer::error,
            this, std::bind(&BeerGameServer::playerError, this, playerInterfaceServer));
    connect(playerInterfaceServer, &PlayerInterfaceServer::jsonReceived,
            this, std::bind(&BeerGameServer::receiveJson, this, playerInterfaceServer, std::placeholders::_1));
    connect(playerInterfaceServer, &PlayerInterfaceServer::logMessage,
            this, &BeerGameServer::displayLogMessage);
    connect(this, &BeerGameServer::logMessage,
            this, &BeerGameServer::displayLogMessage);

    m_clients.append(playerInterfaceServer);
    emit logMessage(QStringLiteral("New client Connected"));
}

void BeerGameServer::sendJson(PlayerInterfaceServer* destination, const QJsonObject& message)
{
    Q_ASSERT(destination);
    destination->sendJson(message);
}

void BeerGameServer::receiveJson(PlayerInterfaceServer* sender, const QJsonObject& doc)
{
    Q_ASSERT(sender);
    emit logMessage("JSON received " + QString::fromUtf8(QJsonDocument(doc).toJson()));
    if (sender->getRole() < 0)
        return jsonFromLoggedOut(sender, doc);

    jsonFromLoggedIn(sender, doc);
}

void BeerGameServer::jsonFromLoggedIn(PlayerInterfaceServer* sender, const QJsonObject &docObj) {
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) != 0)
        return;

    const QJsonValue nBeersVal = docObj.value(QLatin1String("numberOfBeers"));
    if(nBeersVal.isNull()) {
        return;
    }
    const QString nBeers = nBeersVal.toString().trimmed();
    if (nBeers.isEmpty())
        return;
}

void BeerGameServer::jsonFromLoggedOut(PlayerInterfaceServer* sender, const QJsonObject &docObj) {
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) != 0)
        return;

    // process for game attribute
    const QJsonValue gameNumVal = docObj.value(QLatin1String("game"));
    if (gameNumVal.isNull() || !gameNumVal.isString())
        return;
    const int gameNumber = gameNumVal.toInt();
    if (gameNumber<=0 || gameNumber>m_games.length())
        return;

    // process for role attribute
    const QJsonValue roleVal = docObj.value(QLatin1String("role"));
    if (roleVal.isNull() || !roleVal.isString())
        return;
    const int role = roleVal.toInt();
    if (role < 0)
        return;

    sender->setRole(role);
    sender->setGame(m_games[gameNumber-1]);

    QJsonObject successMessage;
    successMessage["type"] = QStringLiteral("login");
    successMessage["success"] = true;
    sendJson(sender, successMessage);
}

void BeerGameServer::playerDisconnected(PlayerInterfaceServer *sender)
{
    m_clients.removeAll(sender);
    int playerRole = sender->getRole();
    if (playerRole >= 0) {
        QJsonObject disconnectedMessage;
        disconnectedMessage["type"] = QStringLiteral("playerDisconnected");
        disconnectedMessage["role"] = playerRole;
//        broadcast(disconnectedMessage, nullptr);
    }
    sender->deleteLater();
}

void BeerGameServer::playerError(PlayerInterfaceServer* sender)
{
    Q_UNUSED(sender)
    int playerRole= sender->getRole();
    emit logMessage("Error from " + QString::number(playerRole));
}

void BeerGameServer::stopServer()
{
    for (PlayerInterfaceServer *worker : m_clients) {
        worker->disconnectFromPlayer();
    }
    close();
}

void BeerGameServer::displayLogMessage(const QString &msg)
{
    std::cout << msg.toStdString() << std::endl;
}
