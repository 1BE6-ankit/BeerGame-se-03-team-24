#ifndef BEERGAMESERVER_H
#define BEERGAMESERVER_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>
#include <QObject>

#include "playerinterface.h"
#include "player.h"
#include "game.h"

class Player;
class Game;

class PlayerInterfaceServer : public PlayerInterface {
    Q_OBJECT
    public:
        explicit PlayerInterfaceServer(QWidget* parent = nullptr);
        virtual bool setSocketDescriptor(qintptr socketDescriptor);
        void sendJson(const QJsonObject& jsonData);
        void setRole(int role);

    signals:
        void jsonReceived(const QJsonObject& jsonDoc);
        void disconnectedFromPlayer();
        void error();
        void logMessage(const QString& msg);

    public slots:
        void disconnectFromPlayer();

    private slots:
        void receiveJson();

    private:
        QTcpSocket* m_playerSocket;
};


class BeerGameServer : public QTcpServer {
    Q_OBJECT
    Q_DISABLE_COPY(BeerGameServer)
    public:
        explicit BeerGameServer(QObject* parent = nullptr);

    protected:
        void incomingConnection(qintptr socketDescriptor) override;

    signals:
        void logMessage(const QString& msg);

    public slots:
        void stopServer();
        void displayLogMessage(const QString& msg);

    private slots:
        void receiveJson(PlayerInterfaceServer* sender, const QJsonObject& doc);
        void sendJson(PlayerInterfaceServer* destination, const QJsonObject& message);
        void playerDisconnected(PlayerInterfaceServer* sender);
        void playerError(PlayerInterfaceServer* sender);

    private:
        void jsonFromLoggedOut(PlayerInterfaceServer* sender, const QJsonObject& doc);
        void jsonFromLoggedIn(PlayerInterfaceServer* sender, const QJsonObject& doc);

    private:
        QVector<PlayerInterfaceServer*> m_clients;
        QVector<Game*> m_games;
};

#endif // BEERGAMESERVER_H
