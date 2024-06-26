/**
 * @file /include/demo01/main_window.hpp
 *
 * @brief Qt based gui for demo01.
 *
 * @date November 2010
 **/
#ifndef demo01_MAIN_WINDOW_H
#define demo01_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "demo01/serialport.h"
#include <QDesktopWidget>

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace demo01 {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);


    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically
    void on_serialport_pushButton_clicked();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
  Serialport serial_view;
};

}  // namespace demo01

#endif // demo01_MAIN_WINDOW_H
