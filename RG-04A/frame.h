#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

class frame : public QFrame
{
	Q_OBJECT
public:
	explicit frame(QWidget *parent = nullptr);
	QTextEdit* Name;
	//params
	QPushButton*	STATb[7];
	QTextEdit*		STATl[7];
	//HPbar
	QPushButton*	HPb[3];
	QTextEdit*		HPl[3];
	QLabel*			HPlb;


};

#endif // FRAME_H
