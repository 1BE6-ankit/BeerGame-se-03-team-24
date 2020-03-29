#include <QTcpSocket>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>

#include <iostream>

#include "beergameserver.h"
#include "playerinterface.h"


PlayerInterfaceServer::PlayerInterfaceServer(QWidget *parent, Player* player) :
    PlayerInterface(parent, player),
    m_playerSocket(new QTcpSocket(this))
{
    connect(m_playerSocket, &QTcpSocket::readyRead,
            this, &PlayerInterfaceServer::receiveJson);
    connect(m_playerSocket, &QTcpSocket::disconnected,
            this, &PlayerInterfaceServer::disconnectedFromPlayer);
    connect(m_playerSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &PlayerInterfaceServer::error);
}

bool PlayerInterfaceServer::setSocketDescriptor(qintptr socketDescriptor)
{
    return m_playerSocket->setSocketDescriptor(socketDescriptor);
}
void PlayerInterfaceServer::disconnectFromPlayer()
{
    m_playerSocket->disconnectFromHost();
}

void PlayerInterfaceServer::setRole(int role)
{
    player->setRole(role);
}

void PlayerInterfaceServer::receiveJson()
{
    QByteArray jsonData;
    QDataStream socketStream(m_playerSocket);
    socketStream.setVersion(QDataStream::Qt_5_14);
    for (;;) {
        socketStream.startTransaction();
        socketStream >> jsonData;
        if (socketStream.commitTransaction()) {
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            if (parseError.error == QJsonParseError::NoError) {
                if (jsonDoc.isObject()) { // and is a JSON object
//                    emit jsonReceived(jsonDoc.object()); // send the message to the central server
                    //
                    // PROCESS  JSON HERE
                    std::cout << QString(jsonDoc.toJson(QJsonDocument::Compact)).toStdString() << std::endl;
                }
                else
                    emit logMessage("Invalid message: " + QString::fromUtf8(jsonData)); //notify the server of invalid data
            } else {
                emit logMessage("Invalid message: " + QString::fromUtf8(jsonData)); //notify the server of invalid data
            }
        } else {
            break;
        }
    }
}

void PlayerInterfaceServer::sendJson(const QJsonObject &json)
{
    // we crate a temporary QJsonDocument forom the object and then convert it
    // to its UTF-8 encoded version. We use QJsonDocument::Compact to save bandwidth
    const QByteArray jsonData = QJsonDocument(json).toJson(QJsonDocument::Compact);
    // we notify the central server we are about to send the message
    emit logMessage("Sending to " + QString::number(getRole()) + " - " + QString::fromUtf8(jsonData));
    // we send the message to the socket in the exact same way we did in the client
    QDataStream socketStream(m_playerSocket);
    socketStream.setVersion(QDataStream::Qt_5_14);
    socketStream << jsonData;
}


void PlayerInterfaceServer::jsonFromLoggedOut(const QJsonObject &docObj)
{
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) != 0)
        return;

    const QJsonValue gameNameVal = docObj.value(QLatin1String("game"));
    if (gameNameVal.isNull() || !gameNameVal.isString())
        return;
    const QString gameName = gameNameVal.toString().simplified();
    if (gameName.isEmpty())
        return;

    const QJsonValue roleVal = docObj.value(QLatin1String("role"));
    if (gameNameVal.isNull() || !gameNameVal.isString())
        return;
    const int role = gameNameVal.toInt();
    if (role < 0)
        return;

    setRole(role);
    QJsonObject successMessage;
    successMessage["type"] = QStringLiteral("login");
    successMessage["success"] = true;
    sendJson(successMessage);
    QJsonObject connectedMessage;
//    connectedMessage["type"] = QStringLiteral("newuser");
//    connectedMessage["username"] = newUserName;
//    broadcast(connectedMessage, sender);
}

void PlayerInterfaceServer::jsonFromLoggedIn(const QJsonObject &docObj)
{
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return;
    if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) != 0)
        return;
    const QJsonValue textVal = docObj.value(QLatin1String("text"));
    if (textVal.isNull() || !textVal.isString())
        return;
    const QString text = textVal.toString().trimmed();
    if (text.isEmpty())
        return;
    QJsonObject message;
    message["type"] = QStringLiteral("message");
    message["text"] = text;
//    message["sender"] = sender->userName();
//    broadcast(message, sender);
}
