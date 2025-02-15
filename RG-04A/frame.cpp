#include "frame.h"
#include "A-def.h"

frame::frame(QWidget *parent) : QFrame(parent)
{
	this->setStyleSheet("background: rgb(100,100,100);");
	Name = new QTextEdit(this);
	Name->setGeometry(10,10,100,30);
	Name->setStyleSheet("background: white;");

	QFont font = Name->font();
	font.setPixelSize(butSizeFont);

	//////////////////////////////////////////////////////////////////////////////////////
	uint16_t varTemp = 500 - 40;
	for (uint8_t i = 0; i<7 ;i++)
	{
		STATb[i] = new QPushButton(this);
		STATb[i]->setGeometry(10,varTemp,150,30);
		STATb[i]->setStyleSheet("color: white;");

		STATb[i]->setFont(font);

		STATl[i] = new QTextEdit(this);
		STATl[i]->setGeometry(10+150+10,varTemp,40,30);
		STATl[i]->setStyleSheet("background: white;");

		varTemp -= 40;
	}

	STATb[0]->setText("Воля");
	STATb[1]->setText("Харизма");
	STATb[2]->setText("Внимание");
	STATb[3]->setText("Интеллект");
	STATb[4]->setText("Ловкость");
	STATb[5]->setText("Сила");
	STATb[6]->setText("Телослож.");

	//////////////////////////////////////////////////////////////////////////////////////
	for (uint8_t i = 0; i<3 ;i++)
	{
		HPb[i] = new QPushButton(this);
		HPb[i]->setStyleSheet("color: white;");

		HPb[i]->setFont(font);

		HPl[i] = new QTextEdit(this);
		HPl[i]->setStyleSheet("background: white;");
		HPl[i]->setFont(font);
	}
	HPlb = new QLabel(this);
	HPlb->setStyleSheet("color: white;");
	HPlb->setFont(font);

	varTemp = 240;
	HPb[0]->setGeometry(varTemp, 430, 80, 60);	HPb[0]->setText("Жизнь:");	varTemp+=80;
	HPl[0]->setGeometry(varTemp, 430, 60, 60);								varTemp+=60;
	HPb[1]->setGeometry(varTemp, 430, 80, 60);	HPb[1]->setText("Урон:");	varTemp+=80;
	HPl[1]->setGeometry(varTemp, 430, 60, 60);								varTemp+=60;
	HPb[2]->setGeometry(varTemp, 430, 80, 60);	HPb[2]->setText("Хил:");varTemp+=80;
	HPlb->setGeometry(  varTemp, 430, 60, 60);	HPlb->setText("Ост.:");	varTemp+=60;
	HPl[2]->setGeometry(varTemp, 430, 60, 60);
}


