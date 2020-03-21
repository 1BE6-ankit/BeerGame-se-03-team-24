#include "instructor_ui.h"
#include "ui_instructor_ui.h"

instructor_ui::instructor_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instructor_ui)
{
    ui->setupUi(this);
}

instructor_ui::~instructor_ui()
{
    delete ui;
}
