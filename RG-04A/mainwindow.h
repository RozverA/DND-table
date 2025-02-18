#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "frame.h"
#include <QSettings>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	//frame* fr;
	frame* frm[4];
	//QFrame* fra;
	QPushButton* saveBut;
	QPushButton* loadBut;
	~MainWindow();
private slots:
	void saveProc();
	void loadProc();
};
#endif // MAINWINDOW_H
