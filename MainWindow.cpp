#include "MainWindow.h"
#include "ui_MainWindow.h"
#ifdef ARM
#include <QWSServer>
#endif
#include <QLabel>
#include <QDebug>

#include "JPushButton.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_maxLabelNumber(0)
{
	ui->setupUi(this);

#ifdef ARM
	this->setWindowFlags(Qt::FramelessWindowHint);      //设置窗口标志为无边框
	QWSServer::setCursorVisible(false);			//去掉鼠标
#endif

	for (int i = 0; i < 20; i++)
	{
		addLabelToWidget();
	}

	connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(addLabel()));
	connect(ui->delButton, SIGNAL(clicked(bool)), this, SLOT(delLabel()));

	connect(ui->wideButton, SIGNAL(clicked(bool)), this, SLOT(wideLabel()));
	connect(ui->narrowButton, SIGNAL(clicked(bool)), this, SLOT(narrowLabel()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::addLabelToWidget()
{
//	QLabel *label = new QLabel;
//	label->setText(QString::number(++m_maxLabelNumber));
//	label->setStyleSheet("border: 1px groove gray");

	JPushButton *button = new JPushButton;
	button->setText(QString::number(++m_maxLabelNumber));
	button->setStyleSheet("border: 1px groove gray");
//	button->setFlat(true);

	connect(button, SIGNAL(clicked(bool)), this, SLOT(clickSlot()));

	ui->showWidget->appendWidget(button);
}

void MainWindow::addLabel()
{
	addLabelToWidget();
}

void MainWindow::delLabel()
{
	ui->showWidget->removeWidget(5);
}

void MainWindow::wideLabel()
{
	ui->showWidget->wideWidget(5);
}

void MainWindow::narrowLabel()
{
	ui->showWidget->narrowWidget(5);
}

void MainWindow::clickSlot()
{
	JPushButton *button = reinterpret_cast<JPushButton *>(sender());
	qDebug() << button->text() << "clicked";
}
