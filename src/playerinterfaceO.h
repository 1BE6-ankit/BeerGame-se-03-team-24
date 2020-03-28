#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QDataStream>
#include <QTcpSocket>
#include <QDialog>
#include <string>

#include "player.h"
#include "game.h"
#include "playerwindow.h"
#include "ui_playerwindow.h"

class Player;
class Game;

class QTcpSocket;
class QNetworkSession;
class QComboBox;
class QLineEdit;
class QAbstractSocket;

class PlayerInterface : public QDialog {
public:
};

class PlayerClient : public PlayerInterface {
public:
    PlayerClient(int role);

    void receiveOrder(int);
    void receiveShipment(int);
    void placeOrder(int);
    void placeShipment(int);
    void updateUi();

    void setUi(Ui::PlayerWindow* pUi);
    void setPlayer(Player* player);
    void setGame(Game* game);

private slots:
    void sendDataToServer();
    void getDataFromServer();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableConnectButton();
    void sessionOpened();

private:
    QComboBox *hostCombo = nullptr;
    QLineEdit *portLineEdit = nullptr;
    QComboBox *roleCombo = nullptr;
    QLabel *statusLabel = nullptr;
    QPushButton *connectButton = nullptr;

    QTcpSocket* tcpSocket;
    QNetworkSession *networkSession = nullptr;
    QDataStream in;
    std::string ipAddress;

    Ui::PlayerWindow *pUi;
};

class PlayerThread : public PlayerInterface {
public:
    PlayerThread(int role, int socketDescriptor);

    void receiveOrder(int);
    void receiveShipment(int);
    void placeOrder(int);
    void placeShipment(int);
    void updateUi();

    void setUi(Ui::PlayerWindow* pUi);
    void setPlayer(Player* player);
    void setGame(Game* game);

private:
    QTcpSocket* tcpSocket;
};

class PlayerLocal : public PlayerInterface {
public:
    PlayerLocal(int role);

    void receiveOrder(int);
    void receiveShipment(int);
    void placeOrder(int);
    void placeShipment(int);
    void updateUi();

    void setUi(Ui::PlayerWindow* pUi);
    void setPlayer(Player* player);
    void setGame(Game* game);

private:
    Ui::PlayerWindow *pUi;
    bool shipmentPlaced = false;
    bool orderPlaced = false;
};

#endif // PLAYERINTERFACE_
