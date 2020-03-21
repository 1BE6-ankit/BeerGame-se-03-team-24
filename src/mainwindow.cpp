#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player_ui.h"
#include "instructor_ui.h"
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    player_ui ui_player;
    ui_player.setModal(true);
    ui_player.exec();
}

void MainWindow::on_pushButton_clicked()
{
    instructor_ui ui_instructor;
    ui_instructor.setModal(true);
    ui_instructor.exec();
}
