#include "beergameserver.h"

#include <iostream>

#include <QJsonDocument>

GameServer::GameServer(QObject *parent) :
    QTcpServer(parent)
{
}

void GameServer::incomingConnection(qintptr socketDescriptor) {
    PlayerInterfaceServer* playerInterfaceServer = new PlayerInterfaceServer(nullptr, nullptr);
    // try to bind the socket to the interface
    if(!playerInterfaceServer->setSocketDescriptor(socketDescriptor)) {
        playerInterfaceServer->deleteLater();
        return;
    }

    connect(playerInterfaceServer, &PlayerInterfaceServer::disconnectedFromPlayer,
            this, std::bind(&GameServer::playerDisconnected, this, playerInterfaceServer));
    connect(playerInterfaceServer, &PlayerInterfaceServer::error,
            this, std::bind(&GameServer::playerError, this, playerInterfaceServer));
//    connect(playerInterfaceServer, &PlayerInterfaceServer::jsonReceived,
//            this, std::bind(&GameServer::jsonReceived, this, playerInterfaceServer, std::placeholders::_1));
    connect(playerInterfaceServer, &PlayerInterfaceServer::logMessage,
            this, &GameServer::displayLogMessage);
    connect(this, &GameServer::logMessage,
            this, &GameServer::displayLogMessage);

    m_clients.append(playerInterfaceServer);
    emit logMessage(QStringLiteral("New client Connected"));
}

//void GameServer::sendJson(PlayerInterfaceServer *destination, const QJsonObject &message)
//{
//    Q_ASSERT(destination); // make sure destination is not null
//    destination->sendJson(message); // call directly the worker method
//}

//void GameServer::broadcast(const QJsonObject &message, GameServer *exclude)
//{
//    // iterate over all the workers that interact with the clients
//    for (PlayerInterfaceServer *worker : m_clients) {
////        if (worker == exclude)
////            continue; // skip the worker that should be excluded
//        sendJson(worker, message); //send the message to the worker
//    }
//}

//void GameServer::jsonReceived(PlayerInterfaceServer *sender, const QJsonObject &doc)
//{
//    Q_ASSERT(sender);
//    emit logMessage("JSON received " + QString::fromUtf8(QJsonDocument(doc).toJson()));
//    if (sender->getRole() < 0)
//        return jsonFromLoggedOut(sender, doc);
//    jsonFromLoggedIn(sender, doc);
//}

void GameServer::playerDisconnected(PlayerInterfaceServer *sender)
{
    m_clients.removeAll(sender);
    int playerRole= sender->getRole();
    if (playerRole >= 0) {
        QJsonObject disconnectedMessage;
        disconnectedMessage["type"] = QStringLiteral("userdisconnected");
        disconnectedMessage["username"] = playerRole;
//        broadcast(disconnectedMessage, nullptr);
        emit logMessage(playerRole + QString::number(playerRole));
    }
    sender->deleteLater();
}

void GameServer::playerError(PlayerInterfaceServer *sender)
{
    Q_UNUSED(sender)
    int playerRole= sender->getRole();
    emit logMessage("Error from " + QString::number(playerRole));
}

void GameServer::stopServer()
{
    for (PlayerInterfaceServer *worker : m_clients) {
        worker->disconnectFromPlayer();
    }
    close();
}

void GameServer::displayLogMessage(const QString &msg)
{
    std::cout << msg.toStdString() << std::endl;
}
