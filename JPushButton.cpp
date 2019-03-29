#include "JPushButton.h"
#include <QEvent>

JPushButton::JPushButton(QWidget *parent) : QPushButton(parent),
	moveFlag(false)
{

}

void JPushButton::mousePressEvent(QMouseEvent *e)
{
	QPushButton::mousePressEvent(e);
	return QWidget::mousePressEvent(e);
}

void JPushButton::mouseReleaseEvent(QMouseEvent *e)
{
	if (!moveFlag)
		QPushButton::mouseReleaseEvent(e);
	moveFlag = false;
	return QWidget::mouseReleaseEvent(e);
}

void JPushButton::mouseMoveEvent(QMouseEvent *e)
{
	moveFlag = true;
	QPushButton::mouseMoveEvent(e);
	return QWidget::mouseMoveEvent(e);
}


