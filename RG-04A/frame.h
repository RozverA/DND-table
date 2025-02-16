#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>

class frame : public QFrame
{
	Q_OBJECT
public:
	explicit frame(QWidget *parent = nullptr);
	QTextEdit* Name;
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
private slots:
	void fotoClickIvt();
	void hpMaxF();
	void Dmg();
	void Heal();
};

#endif // FRAME_H
