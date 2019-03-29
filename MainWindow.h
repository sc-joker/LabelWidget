#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void					addLabelToWidget();

public slots:
	void					addLabel();
	void					delLabel();

	void					wideLabel();
	void					narrowLabel();

	void					clickSlot();

private:
	Ui::MainWindow *ui;
	int						m_maxLabelNumber;
};

#endif // MAINWINDOW_H
