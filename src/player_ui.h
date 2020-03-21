#ifndef PLAYER_UI_H
#define PLAYER_UI_H

#include <QDialog>

namespace Ui {
class player_ui;
}

class player_ui : public QDialog
{
    Q_OBJECT

public:
    explicit player_ui(QWidget *parent = nullptr);
    ~player_ui();

private:
    Ui::player_ui *ui;
};

#endif // PLAYER_UI_H
