#include "demo01/serialport.h"
#include "ui_serialport.h"

Serialport::Serialport(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Serialport)
{
  ui->setupUi(this);
  QDesktopWidget *deskdop=QApplication::desktop();
  move((deskdop->width()-2*this->width())/2, (deskdop->height()-2*this ->height())/2);

}

Serialport::~Serialport()
{
  delete ui;

}

