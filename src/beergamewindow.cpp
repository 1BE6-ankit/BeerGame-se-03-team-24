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

    InstructorWindow* instructorW = new InstructorWindow(this);
    instructorW->show();

    GameServer gameServer;
    if(!gameServer.listen(QHostAddress::Any, 9898)) {
        std::cout << "SerVER STARTED" << std::endl;
    }


//    this->hide();
}
