#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTieUpPrintTest.h"
#include <QDateTime>
#include "TieupPrint.h"
class QTieUpPrintTest : public QMainWindow, public RcvTipUpCallBack
{
	Q_OBJECT

public:
	QTieUpPrintTest(QWidget *parent = Q_NULLPTR);
	~QTieUpPrintTest();

	public slots:
	void on_pushButton_OpenSerial_clicked();
	void on_pushButton_OffSerial_clicked();
	void on_pushButton_WinccPrivileges_clicked();
	void on_pushButton_ScreenPrivileges_clicked();
	void on_pushButton_Device_Status_clicked();
	void on_pushButton_Ink_Status_clicked();
	void on_pushButton_Print_clicked();
private:
	void __stdcall RcvCallBackEx(int type, QString rcv);
	void WriteMsgList(QString msg);
	Ui::QTieUpPrintTestClass ui;
	TieupPrint* m_TieUp;
};
