#ifndef JPUSHBUTTON_H
#define JPUSHBUTTON_H

#include <QPushButton>

class JPushButton : public QPushButton
{
public:
	explicit JPushButton(QWidget *parent = 0);

protected:
	void				mousePressEvent(QMouseEvent *e);
	void				mouseReleaseEvent(QMouseEvent *e);
	void				mouseMoveEvent(QMouseEvent *e);

private:
	bool				moveFlag;
};

#endif // JPUSHBUTTON_H
