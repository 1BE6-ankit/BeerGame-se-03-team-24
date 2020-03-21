#ifndef INSTRUCTOR_UI_H
#define INSTRUCTOR_UI_H

#include <QDialog>

namespace Ui {
class instructor_ui;
}

class instructor_ui : public QDialog
{
    Q_OBJECT

public:
    explicit instructor_ui(QWidget *parent = nullptr);
    ~instructor_ui();

private:
    Ui::instructor_ui *ui;
};

#endif // INSTRUCTOR_UI_H
