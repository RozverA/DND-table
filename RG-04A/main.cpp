#include "mainwindow.h"

#include <QApplication>

MainWindow* ptrW;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	ptrW = &w;
	w.show();
	return a.exec();
}
