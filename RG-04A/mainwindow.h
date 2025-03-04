#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "frame.h"
#include <QSettings>
#include <QApplication>

extern frame* ptrFrame[4];

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
	QPushButton* nextBut;
	~MainWindow();
private slots:
	void saveProc();
	void loadProc();
	void nextProc();
};
#endif // MAINWINDOW_H
