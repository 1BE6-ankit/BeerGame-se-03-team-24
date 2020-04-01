#ifndef PLAYERCLIENT_H
#define PLAYERCLIENT_H
#include <QDialog>
#include <QHostAddress>
#include <QTcpSocket>
class PlayerClient: public QObject
{
    Q_OBJECT
        Q_DISABLE_COPY(PlayerClient)
    public:
        explicit PlayerClient(QObject *parent = nullptr);
        QString playerName = "";
    public slots:
        void connectToServer(const QHostAddress &address, quint16 port);
        void login(const int &GameId, const int& role);
        void sendMessage(const QString &text);
        void disconnectFromHost();
    private slots:
        void onReadyRead();
    signals:
        void connected();
        void loggedIn();
        void loginError(const QString &reason);
        void disconnected();
        void messageReceived(const QString &sender, const QString &text);
        //void error(QAbstractSocket::SocketError socketError);
        void userJoined(const QString &username);
        void userLeft(const QString &username);
    private:
        QTcpSocket *m_clientSocket;
        bool m_loggedIn;
        void jsonReceived(const QJsonObject &doc);
};

#endif // PLAYERCLIENT_H
