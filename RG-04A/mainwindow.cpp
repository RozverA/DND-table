#include "mainwindow.h"
#include <QSettings>

QSettings sett("save.txt",QSettings::IniFormat);
frame* ptrFrame[4];

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent)
{
	this->setGeometry(0,0,1800,1000);
	this->setMinimumSize(1800,1000);
	//this->setMaximumSize(1800,1000);
	this->setWindowTitle("Персонажник");

	saveBut = new QPushButton(this);
	saveBut->setGeometry(1700,600,100,100);
	saveBut->setText("S\nA\nV\nE");
	connect(saveBut,SIGNAL(clicked()),this,SLOT(saveProc() ) );

	loadBut = new QPushButton(this);
	loadBut->setGeometry(1700,800,100,100);
	loadBut->setText("L\nO\nA\nD");
	connect(loadBut,SIGNAL(clicked()),this,SLOT(loadProc() ) );

	nextBut = new QPushButton(this);
	nextBut->setGeometry(1700,0,100,500);
	nextBut->setText("N\ne\nx\nt");
	nextBut->setStyleSheet("background: red; color: white;");
	connect(nextBut,SIGNAL(clicked()),this,SLOT(nextProc() ) );

	for(uint8_t i = 0; i < 4; i++)
	{
		frm[i] = new frame(this);
		frm[i]->setGeometry(0,0,900,500);
		frm[i]->fraN = i;
		frm[i]->fraS = QString::number(i+1);
		frm[i]->frameCnt = i;
		ptrFrame[i] = frm[i];
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

void MainWindow::saveProc()
{
	for (uint8_t i = 0; i < 4; i++)
	{
		sett.beginGroup("Player"+QString::number(i+1));
			sett.setValue("name",			frm[i]->Name->text() );
			sett.setValue("money",			frm[i]->Ml->text() );

			sett.setValue("KB",			frm[i]->kbl->text() );

			sett.setValue("B1",			frm[i]->wl[0]->text() );
			sett.setValue("B2",			frm[i]->wl[1]->text() );
			sett.setValue("D1",			frm[i]->wl[2]->text() );
			sett.setValue("D2",			frm[i]->wl[3]->text() );

			sett.setValue("vola",			frm[i]->STATl[0]->text() );
			sett.setValue("charisma",		frm[i]->STATl[1]->text() );
			sett.setValue("vnimanie",		frm[i]->STATl[2]->text() );
			sett.setValue("intellect",		frm[i]->STATl[3]->text() );
			sett.setValue("lovkost",		frm[i]->STATl[4]->text() );
			sett.setValue("sila",			frm[i]->STATl[5]->text() );
			sett.setValue("teloslojenie",	frm[i]->STATl[6]->text() );

			for(uint8_t j = 0; j<10; j++)
			{
				sett.setValue("sp1_"+QString::number(j),	frm[i]->spell1[j]->text() );
				sett.setValue("sp2_"+QString::number(j),	frm[i]->spell2[j]->text() );
			}

		sett.endGroup();
	}
}

void MainWindow::loadProc()
{
	for (uint8_t i = 0; i < 4; i++)
	{
		sett.beginGroup("Player"+QString::number(i+1));
			frm[i]->Name->setText(sett.value("name").toString()				);
			frm[i]->Ml->setText(sett.value("money").toString()				);

			frm[i]->wl[0]->setText(sett.value("B1").toString()				);
			frm[i]->wl[1]->setText(sett.value("B2").toString()				);
			frm[i]->wl[2]->setText(sett.value("D1").toString()				);
			frm[i]->wl[3]->setText(sett.value("D2").toString()				);

			frm[i]->STATl[0]->setText(sett.value("vola").toString()			);
			frm[i]->STATl[1]->setText(sett.value("charisma").toString()		);
			frm[i]->STATl[2]->setText(sett.value("vnimanie").toString()		);
			frm[i]->STATl[3]->setText(sett.value("intellect").toString()	);
			frm[i]->STATl[4]->setText(sett.value("lovkost").toString()		);
			frm[i]->STATl[5]->setText(sett.value("sila").toString()			);
			frm[i]->STATl[6]->setText(sett.value("teloslojenie").toString() );

			for(uint8_t j = 0; j<10; j++)
			{
				frm[i]->spell1[j]->setText(sett.value("sp1_"+QString::number(j)).toString());
				frm[i]->spell2[j]->setText(sett.value("sp2_"+QString::number(j)).toString());
			}

			frm[i]->kbl->setText(sett.value("KB").toString()				);
		sett.endGroup();
	}
}

void MainWindow::nextProc()
{
	uint val = 0;
	for (uint8_t i = 0; i < 4; i++)
	{
		for(uint8_t spell = 0; spell < 10; spell++)
		{
			val = frm[i]->spell3[spell]->text().toInt();
			if(!val){continue;}
			val--;
			frm[i]->spell3[spell]->setText(QString::number(val));
		}

	}
}

