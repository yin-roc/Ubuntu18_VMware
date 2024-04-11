#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QWidget>
#include <QDesktopWidget>
#include <QTimer>

namespace Ui {
class Serialport;
}

class Serialport : public QWidget
{
  Q_OBJECT

public:
  explicit Serialport(QWidget *parent = nullptr);
  ~Serialport();

private:
  Ui::Serialport *ui;
  QTimer *timer;

signal:
  void back_to_main_Signal();

private slots:
  void Send_back_to_main_slots();

};

#endif // SERIALPORT_H
