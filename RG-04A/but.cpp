#include "but.h"
#include "mainwindow.h"


But::But(QWidget *parent) : QPushButton(parent)
{
	addr = 0;
}

void But::set()
{
	uint8_t var = this->text().toInt();
	uint8_t var2 = ptrFrame[this->frm]->spell1[this->addr]->text().toInt();
	if(var != 0) {return;}
	ptrFrame[this->frm]->spell3[this->addr]->setText(QString::number(var2));
}
