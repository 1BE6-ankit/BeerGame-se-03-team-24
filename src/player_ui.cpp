#include "player_ui.h"
#include "ui_player_ui.h"

player_ui::player_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::player_ui)
{
    ui->setupUi(this);
}

player_ui::~player_ui()
{
    delete ui;
}
