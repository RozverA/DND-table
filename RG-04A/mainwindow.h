#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "frame.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	//frame* fr;
	frame* frm[4];
	//QFrame* fra;
	~MainWindow();
};
#endif // MAINWINDOW_H
