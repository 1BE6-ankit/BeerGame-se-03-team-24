#ifndef GAME_UI_H
#define GAME_UI_H

#include <QMainWindow>
#include "game.h"
namespace Ui {
class Game_ui;
}

class Game_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game_ui(QWidget *parent = nullptr, std::shared_ptr<Game> p = nullptr);
    ~Game_ui();

private slots:
    void on_addPlayer_clicked();

private:
    Ui::Game_ui *ui;
    std::shared_ptr<Game> game;
    int counter;
};

#endif // GAME_UI_H
