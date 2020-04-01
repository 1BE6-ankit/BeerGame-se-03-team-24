#include "beergameserverwindow.h"
#include "ui_beergameserverwindow.h"

#include <iostream>

#include "beergameserver.h"

BeerGameServerWindow::BeerGameServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BeerGameServerWindow)
{
    ui->setupUi(this);
    ui->stopServerBtn->setEnabled(false);
}

BeerGameServerWindow::~BeerGameServerWindow()
{
    delete ui;
}

//void BeerGameServerWindow::on_guestBtn_clicked()
//{
//    ui->loginBtn->setText("You clicked");

//    BeerGameServer* gameServer = new BeerGameServer;
//    if(!gameServer->listen(QHostAddress(QString("10.42.0.1")), 9898)) {
//        std::cout << "Error while establishing server" << std::endl;
//    }

//    this->hide();
//}

void BeerGameServerWindow::on_start_server_btn_clicked() {
    QString ipAddress = ui->port_input->text();
    int portValue = ui->port_input->text().toInt();

    beerGameServer = new BeerGameServer;
    if(!beerGameServer->listen(QHostAddress(ipAddress), portValue)) {
        std::cout << "Error while establishing server" << std::endl;
        ui->stopServerBtn->setEnabled(false);
        return;
    }

    ui->settingsGroup->setEnabled(false);
    ui->stopServerBtn->setEnabled(true);
}

void BeerGameServerWindow::on_stopServerBtn_clicked()
{
    beerGameServer->stopServer();
    ui->settingsGroup->setEnabled(true);
    ui->stopServerBtn->setEnabled(false);
}
