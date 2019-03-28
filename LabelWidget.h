#ifndef LABELWIDGET_H
#define LABELWIDGET_H

#include <QWidget>
#include <QList>

namespace Ui {
class LabelWidget;
}

class LabelWidget : public QWidget
{
	Q_OBJECT

#define WIDGET_MIN_HEIGHT		5

public:
	explicit LabelWidget(QWidget *parent = 0);
	~LabelWidget();

	void					appendWidget(QWidget *w);
	void					removeWidget(QWidget *w);
	void					removeWidget(int index);

	void					wideWidget(int step);
	void					narrowWidget(int step);

private:
	void					upShiftPixel(int pix);
	void					downShiftPixel(int pix);

	void					reflushWidgets();

private:
	Ui::LabelWidget *ui;


protected:
	void				mousePressEvent(QMouseEvent *);
	void				mouseReleaseEvent(QMouseEvent *);
	void				mouseMoveEvent(QMouseEvent *);

private:
	QList<QWidget *>			m_widgetList;
	int							m_childWidgetHeight;

	int							m_moveFlag;
	int							m_prevPixY;
};

#endif // LABELWIDGET_H
