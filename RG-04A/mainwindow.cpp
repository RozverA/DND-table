#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent)
{
	this->setGeometry(0,0,1800,1000);
	this->setMinimumSize(1800,1000);
	//this->setMaximumSize(1800,1000);
	this->setWindowTitle("Персонажник");

	for(uint8_t i = 0; i < 4; i++)
	{
		frm[i] = new frame(this);
		frm[i]->setGeometry(0,0,900,500);
		frm[i]->fraN = i+1;
		frm[i]->fraS = QString::number(i+1);
	}
	frm[0]->setGeometry(0,0,800,500);
	frm[1]->setGeometry(850,0,800,500);
	frm[2]->setGeometry(0,500,800,500);
	frm[3]->setGeometry(850,500,800,500);

	frm[0]->setStyleSheet("background: #4682B4;");
	frm[1]->setStyleSheet("background: #5F9EA0;");
	frm[2]->setStyleSheet("background: #FF4500;");
	frm[3]->setStyleSheet("background: #8A2BE2;");
}

MainWindow::~MainWindow()
{
}

