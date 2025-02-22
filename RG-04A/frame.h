#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include "but.h"

class frame : public QFrame
{
	Q_OBJECT
public:
	explicit frame(QWidget *parent = nullptr);
	uint8_t frameCnt;

	QLineEdit* Name;
	//params
	QPushButton*	STATb[7];
	QLineEdit*		STATl[7];
	//HPbar
	QPushButton*	HPb[3];
	QLineEdit*		HPl[3];
	QLabel*			HPlb;
	//foto
	QLabel* foto;
	QPushButton* fotoClick;
	//number
	QString fraS;
	uint8_t fraN;
	//money
	QLabel*			Mlb;
	QLineEdit*		Ml;

	//wearpon
	QLabel*			wlb[4];
	QLineEdit*		wl[4];

	//kb
	QLabel*			kblb;
	QLineEdit*		kbl;

	//spels
	QLineEdit* spell1[10];
	QLineEdit* spell2[10];
	But* spell3[10];

private slots:
	void fotoClickIvt();
	void hpMaxF();
	void Dmg();
	void Heal();
};

#endif // FRAME_H
