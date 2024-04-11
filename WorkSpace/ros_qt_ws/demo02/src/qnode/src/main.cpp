#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Qt
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("主选择界面");
    w.resize(800,600);
    w.move(800, 400);
    w.show();
    return a.exec();
}
