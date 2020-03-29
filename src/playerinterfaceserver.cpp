#include <QTcpSocket>
#include <QDataStream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>

#include <iostream>

#include "beergameserver.h"
#include "playerinterface.h"


PlayerInterfaceServer::PlayerInterfaceServer(QWidget *parent) :
    PlayerInterface(parent),
    m_playerSocket(new QTcpSocket)
{
    connect(m_playerSocket, &QTcpSocket::readyRead,
            this, &PlayerInterfaceServer::receiveJson);
    connect(m_playerSocket, &QTcpSocket::disconnected,
            this, &PlayerInterfaceServer::disconnectFromPlayer);
    connect(m_playerSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &PlayerInterfaceServer::error);
}

void PlayerInterfaceServer::receiveJson()
{
    QByteArray jsonData;
    QDataStream socketStream(m_playerSocket);
//    socketStream.setVersion(QDataStream::Qt_5_14);
    for (;;) {
        socketStream.startTransaction();
        socketStream >> jsonData;
        std::cout << "Message: " << QString::fromUtf8(jsonData).toStdString() << std::endl;
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
    const QByteArray jsonData = QJsonDocument(json).toJson(QJsonDocument::Compact);
    emit logMessage("Sending to " + QString::number(getRole()) + " - " + QString::fromUtf8(jsonData));
    QDataStream socketStream(m_playerSocket);
//    socketStream.setVersion(QDataStream::Qt_5_14);
    socketStream << jsonData;
}


bool PlayerInterfaceServer::setSocketDescriptor(qintptr socketDescriptor) {
    return m_playerSocket->setSocketDescriptor(socketDescriptor);
}

void PlayerInterfaceServer::disconnectFromPlayer() {
    m_playerSocket->disconnectFromHost();
    emit logMessage("Client disconnected");
}

void PlayerInterfaceServer::setRole(int role) {
    player->setRole(role);
}

