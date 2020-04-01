#include "beergamewindow.h"
#include "ui_beergamewindow.h"

#include  "instructorwindow.h"
#include "game.h"
#include "player.h"
#include "beergameserver.h"

#include <iostream>

BeerGameWindow::BeerGameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BeerGameWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":images/background.jpg"));
}

BeerGameWindow::~BeerGameWindow()
{
    delete ui;
}

void BeerGameWindow::on_guestBtn_clicked()
{
    ui->loginBtn->setText("You clicked");

//    InstructorWindow* instructorW = new InstructorWindow(this);
//    instructorW->show();

    BeerGameServer* gameServer = new BeerGameServer;
    if(!gameServer->listen(QHostAddress(QString("10.42.0.1")), 9898)) {
        std::cout << "Error while establishing server" << std::endl;
    }

//    this->hide();
}
