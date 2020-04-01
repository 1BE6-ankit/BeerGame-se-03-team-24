#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H
#include <QWidget>
#include "playerclient.h"
namespace Ui {
class ClientInterface;
}
class ClientInterface : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ClientInterface)
public:
    explicit ClientInterface(QWidget *parent = nullptr);
    ~ClientInterface();
private:
    Ui::ClientInterface *ui;
    PlayerClient *m_PlayerClient;
    QString m_lastUserName;
private slots:
    void connectedToServer();
    void attemptLogin(const int &GameId, const int &role);
    void loggedIn();
    void loginFailed(const QString &reason);
    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    //void userJoined(const QString &username);
    //void userLeft(const QString &username);
    //void error(QAbstractSocket::SocketError socketError);
    void attemptConnection();
};
#endif // CLIENTINTERFACE_H
