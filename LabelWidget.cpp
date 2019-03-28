#include "LabelWidget.h"
#include "ui_LabelWidget.h"
#include <QMouseEvent>
#include <QDebug>

LabelWidget::LabelWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LabelWidget),
	m_childWidgetHeight(40), m_moveFlag(false), m_prevPixY(0)
{
	ui->setupUi(this);
}

LabelWidget::~LabelWidget()
{
	delete ui;
}

void LabelWidget::appendWidget(QWidget *w)
{
	if (NULL == w)
		return;

//	qDebug() << "add widget list size: " << m_widgetList.size();

	w->setParent(this);
	w->setGeometry(0, m_childWidgetHeight * m_widgetList.size(), width(), m_childWidgetHeight);
	w->show();

	m_widgetList.append(w);
	reflushWidgets();
}

void LabelWidget::removeWidget(QWidget *w)
{
	if (NULL == w)
		return;

	for (int i = 0; i < m_widgetList.size(); i++)
	{
		if (w == m_widgetList.at(i)) {
			m_widgetList.removeAt(i);
//			qDebug() << "del widget list size: " << m_widgetList.size();
			delete w;
			break;
		}
	}

	reflushWidgets();
}

void LabelWidget::removeWidget(int index)
{
	if (index < 0 || index >= m_widgetList.size())
		return;

	QWidget *w = m_widgetList.at(index);
	removeWidget(w);
}

void LabelWidget::wideWidget(int step)
{
	m_childWidgetHeight += step;

	if (m_childWidgetHeight < WIDGET_MIN_HEIGHT)
		m_childWidgetHeight = WIDGET_MIN_HEIGHT;
	else if(m_childWidgetHeight > (width() / 2))
		m_childWidgetHeight = width() / 2;

	reflushWidgets();
}

void LabelWidget::narrowWidget(int step)
{
	m_childWidgetHeight -= step;

	if (m_childWidgetHeight < WIDGET_MIN_HEIGHT)
		m_childWidgetHeight = WIDGET_MIN_HEIGHT;
	else if(m_childWidgetHeight > (width() / 2))
		m_childWidgetHeight = width() / 2;

	reflushWidgets();
}

void LabelWidget::upShiftPixel(int pix)
{
	int widgetSize = m_widgetList.size();
	if (widgetSize * m_childWidgetHeight <= height())
		return;

	for (int i = 0; i < widgetSize; i++)
	{
		QWidget *w = m_widgetList.at(i);
		if (NULL == w)
			continue;

		int wy = w->y() - pix;
		w->move(0, wy);
	}

}

void LabelWidget::downShiftPixel(int pix)
{
	int widgetSize = m_widgetList.size();
	if (widgetSize * m_childWidgetHeight <= height())
		return;

	for (int i = 0; i < widgetSize; i++)
	{
		QWidget *w = m_widgetList.at(i);
		if (NULL == w)
			continue;

		int wy = w->y() + pix;
		w->move(0, wy);
	}
}

void LabelWidget::reflushWidgets()
{
	for (int i = 0; i < m_widgetList.size(); i++)
	{
		QWidget *w = m_widgetList.at(i);
		if (NULL == w) {
			m_widgetList.removeAt(i);
			continue;
		}

		w->setGeometry(0, i * m_childWidgetHeight, width(), m_childWidgetHeight);
	}
}

void LabelWidget::mousePressEvent(QMouseEvent *e)
{
	m_moveFlag = true;
	m_prevPixY = e->y();
}

void LabelWidget::mouseReleaseEvent(QMouseEvent *)
{
	m_moveFlag = false;
}

void LabelWidget::mouseMoveEvent(QMouseEvent *e)
{
	if (!m_moveFlag)
		return;

	int mouseDiffY = e->y() - m_prevPixY;
	if (mouseDiffY < 0) {
		QWidget *lastW = m_widgetList.last();
		if (NULL == lastW)
			return;

		if ((lastW->y() + m_childWidgetHeight - height()) > -mouseDiffY)
			upShiftPixel(-mouseDiffY);
		else
			upShiftPixel(lastW->y() + m_childWidgetHeight - height());
	} else {
		QWidget *firstW = m_widgetList.first();
		if (NULL == firstW)
			return;

		if (firstW->y() < -mouseDiffY)
			downShiftPixel(mouseDiffY);
		else
			downShiftPixel(-firstW->y());
	}

	m_prevPixY = e->y();
}
