#ifndef BUT_H
#define BUT_H
#include "A-def.h"
#include <QPushButton>

class But : public QPushButton
{
	Q_OBJECT
public:
	explicit But(QWidget *parent = nullptr);
	uint8_t addr;
	uint8_t frm;
private slots:
	void set();
};

#endif // BUT_H
