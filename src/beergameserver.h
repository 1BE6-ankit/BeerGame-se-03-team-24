#ifndef BEERGAMESERVER_H
#define BEERGAMESERVER_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>
#include <QObject>

#include "playerinterface.h"
#include "player.h"

class Player;

class PlayerInterfaceServer : public PlayerInterface {
    Q_OBJECT
public:
    explicit PlayerInterfaceServer(QWidget *parent = nullptr, Player* player = nullptr);
    virtual bool setSocketDescriptor(qintptr socketDescriptor);
    void setPlayerRole(int role);
    void sendJson(const QJsonObject &jsonData);
    void setRole(int role);

    void jsonFromLoggedOut(const QJsonObject &docObj);
    void jsonFromLoggedIn(const QJsonObject &docObj);

signals:
    void jsonReceived(const QJsonObject &jsonDoc);
    void disconnectedFromPlayer();
    void error();
    void logMessage(const QString &msg);

public slots:
    void disconnectFromPlayer();

private slots:
    void receiveJson();

private:
    QTcpSocket *m_playerSocket;
};


class GameServer : public QTcpServer {
    Q_OBJECT
    Q_DISABLE_COPY(GameServer)
public:
    explicit GameServer(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void logMessage(const QString &msg);

public slots:
    void stopServer();
    void displayLogMessage(const QString &msg);

private slots:
//    void jsonReceived(PlayerInterfaceServer *sender, const QJsonObject &doc);
    void playerDisconnected(PlayerInterfaceServer *sender);
    void playerError(PlayerInterfaceServer *sender);

private:
//    void jsonFromLoggedOut(PlayerInterfaceServer *sender, const QJsonObject &doc);
//    void jsonFromLoggedIn(PlayerInterfaceServer *sender, const QJsonObject &doc);
//    void sendJson(PlayerInterfaceServer *destination, const QJsonObject &message);
    QVector<PlayerInterfaceServer *> m_clients;

};

#endif // BEERGAMESERVER_H













