#include "frame.h"
#include "A-def.h"
#include <QValidator>

uint8_t FRAN = 0;

frame::frame(QWidget *parent) : QFrame(parent)
{
	this->setStyleSheet("background: rgb(100,100,100);");
	Name = new QLineEdit(this);
	Name->setGeometry(680,310,100,30);
	Name->setStyleSheet("background: white;");

	QFont font = Name->font();
	font.setPixelSize(butSizeFont);
	QFont fontLow = Name->font();
	fontLow.setPixelSize(14);

	//////////////////////////////////////////////////////////////////////////////////////
	uint16_t varTemp = 500 - 40;
	for (uint8_t i = 0; i<7 ;i++)
	{
		STATb[i] = new QPushButton(this);
		STATb[i]->setGeometry(10,varTemp,150,30);
		STATb[i]->setStyleSheet("color: white;");

		STATb[i]->setFont(font);

		STATl[i] = new QLineEdit(this);
		STATl[i]->setGeometry(10+150+10,varTemp,40,30);
		STATl[i]->setStyleSheet("background: white;");
		STATl[i]->setText("0");

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

		HPl[i] = new QLineEdit(this);
		HPl[i]->setStyleSheet("background: white;");
		HPl[i]->setFont(font);
	}
	HPlb = new QLabel(this);
	HPlb->setStyleSheet("color: white;");
	HPlb->setFont(font);

	varTemp = 240;
	HPb[0]->setGeometry(varTemp, 430, 80, 60);	HPb[0]->setText("HP:");	varTemp+=80;
	connect(HPb[0],SIGNAL(clicked()),this,SLOT(hpMaxF() ) );
	HPl[0]->setGeometry(varTemp, 430, 60, 60);								varTemp+=60;
	HPb[1]->setGeometry(varTemp, 430, 80, 60);	HPb[1]->setText("Урон:");	varTemp+=80;
	connect(HPb[1],SIGNAL(clicked()),this,SLOT(Dmg() ) );
	HPl[1]->setGeometry(varTemp, 430, 60, 60);								varTemp+=60;
	HPb[2]->setGeometry(varTemp, 430, 80, 60);	HPb[2]->setText("Хил:");	varTemp+=80;
	connect(HPb[2],SIGNAL(clicked()),this,SLOT(Heal() ) );
	HPlb->setGeometry(  varTemp, 430, 60, 60);	HPlb->setText("Ост.:");		varTemp+=60;
	HPl[2]->setGeometry(varTemp, 430, 60, 60);

	//////////////////////////////////////////////////////////////////////////////////////
	foto = new QLabel(this);
	fotoClick = new QPushButton(this);
	fotoClick->setGeometry(630,310, 50, 30);
	fotoClick->setText("Фото");

	foto->setGeometry(480,10,300,300);

	connect(fotoClick,SIGNAL(clicked()),this,SLOT(fotoClickIvt() ) );
	//////////////////////////////////////////////////////////////////////////////////////

	Mlb = new QLabel(this);
	Mlb->setStyleSheet("color: white;");

	Mlb->setFont(font);

	Ml = new QLineEdit(this);
	Ml->setStyleSheet("background: white;");
	Ml->setFont(font);

	Mlb->setGeometry(580, 360, 90, 40); Mlb->setText("Деньги:");
	Ml->setGeometry(670, 360, 120, 40);	Ml->setText("0");
	//////////////////////////////////////////////////////////////////////////////////////

	for (uint8_t i = 0; i<4 ;i++)
	{
		wlb[i] = new QLabel(this);
		wlb[i]->setStyleSheet("color: white;");

		wlb[i]->setFont(font);

		wl[i] = new QLineEdit(this);
		wl[i]->setStyleSheet("background: white;");
		wl[i]->setFont(font);
	}
	wlb[0]->setGeometry(10, 10, 100, 40); wlb[0]->setText("Урон ББ:");
	wl[0]->setGeometry(110, 10, 40, 40);	wl[0]->setText("1");

	wlb[1]->setGeometry(150, 10, 30, 40); wlb[1]->setText("D:");
	wl[1]->setGeometry(180, 10, 40, 40);	wl[1]->setText("6");

	wlb[2]->setGeometry(10, 60, 100, 40); wlb[2]->setText("Урон ДБ:");
	wl[2]->setGeometry(110, 60, 40, 40);	wl[2]->setText("1");

	wlb[3]->setGeometry(150, 60, 30, 40); wlb[3]->setText("D:");
	wl[3]->setGeometry(180, 60, 40, 40);	wl[3]->setText("6");
	//////////////////////////////////////////////////////////////////////////////////////

	kblb = new QLabel(this);
	kblb->setStyleSheet("color: white;");

	kblb->setFont(font);

	kbl = new QLineEdit(this);
	kbl->setStyleSheet("background: white;");
	kbl->setFont(font);

	kblb->setGeometry(10, 110, 100, 40); kblb->setText("КБ:");
	kbl->setGeometry(110, 110, 40, 40);	kbl->setText("0");
	//////////////////////////////////////////////////////////////////////////////////////
	varTemp = 10;
	for (uint8_t i = 0; i<10 ;i++)
	{
		spell1[i] = new QLineEdit(this);
		spell1[i]->setStyleSheet("background: white;");
		spell1[i]->setFont(font);
		spell1[i]->setValidator(new QIntValidator(0,10,this));
		spell1[i]->setText("0");


		spell2[i] = new QLineEdit(this);
		spell2[i]->setStyleSheet("background: white;");
		spell2[i]->setFont(fontLow);
		//spell2[i]->setValidator(new QIntValidator(0,10,this));

		spell3[i] = new But(this);
		//spell3[i]->setStyleSheet("background: white;");
		spell3[i]->setFont(font);
		spell3[i]->setText("0");
		spell3[i]->addr = i;//cnt
		spell3[i]->frm = FRAN;

		spell1[i]->setGeometry(250,varTemp,40,30);
		spell2[i]->setGeometry(290,varTemp,200,30);
		spell3[i]->setGeometry(490,varTemp,40,30);
		spell3[i]->show();

		connect(spell3[i],SIGNAL(clicked()),spell3[i],SLOT(set() ) );

		varTemp+=40;
	}
	FRAN++;
}

void frame::fotoClickIvt()
{
	QPixmap myPixmap( "player" + fraS+".png" );
	myPixmap =  myPixmap.scaledToWidth(300);
	foto->setPixmap(myPixmap);
}

void frame::hpMaxF()
{
	int a = STATl[6]->text().toInt();
	if(a < 1){return;}
	HPl[0]->setText( QString::number( a*10 ) );
}

void frame::Dmg()
{
	int a = HPl[2]->text().toInt() ;
	if(a < 1){return;}
	int b = HPl[1]->text().toInt();

	if((a-b)<0) {	HPl[2]->setText(QString::number(0));       }
	else		{	HPl[2]->setText(QString::number( a - b ));   }

	HPl[1]->setText("");
}

void frame::Heal()
{
	int a = HPl[2]->text().toInt();
	int b = HPl[1]->text().toInt();
	int c = HPl[0]->text().toInt();
	if(c < (a+b)) { HPl[2]->setText(HPl[0]->text());       }
	else {          HPl[2]->setText(QString::number( a + b ));   }

	HPl[1]->setText("");
}


