#include "QTieUpPrintTest.h"
#pragma execution_character_set("utf-8")
QTieUpPrintTest::QTieUpPrintTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_TieUp = (TieupPrint*)TieupPrintInstance();
	//	ui.lineEdit_QR_code->setText("TEST_510811179004070217 CBPM-KEXIN:2019-09-05");
	//	ui.lineEdit_TEXT_code->setText("TEST_510811179004070217 CBPM-KEXIN:2019-09-05");
	ui.lineEdit_QR_code->setText("�����й���5108#CBPM-KEXIN 2019-09-05");
	ui.lineEdit_TEXT_code->setText("�����й���5108#CBPM-KEXIN 2019-09-05");
	on_pushButton_OpenSerial_clicked();
	on_pushButton_WinccPrivileges_clicked();
	
}

QTieUpPrintTest::~QTieUpPrintTest()
{
	on_pushButton_OffSerial_clicked();
}


void QTieUpPrintTest::on_pushButton_OpenSerial_clicked()
{
	if (m_TieUp->OpenSerial("COM3", 115200, 8, 0, 1, this))
	{
		WriteMsgList("���ڴ򿪳ɹ�");
	}
	else
	{
		WriteMsgList("���ڴ�ʧ��");
	}
}

void QTieUpPrintTest::on_pushButton_OffSerial_clicked()
{
	m_TieUp->OffSerial();
}

void QTieUpPrintTest::on_pushButton_WinccPrivileges_clicked()
{
	if (m_TieUp->GetWinccPrivileges())
	{
		WriteMsgList("���ͻ�ȡ��λ��Ȩ��ָ��ɹ�");
	}
	else
	{
		WriteMsgList("���ͻ�ȡ��λ��Ȩ��ָ��ʧ��");
	}
}

void QTieUpPrintTest::on_pushButton_ScreenPrivileges_clicked()
{
	if (m_TieUp->GetScreenPrivileges())
	{
		WriteMsgList("���ͻ�ȡ������Ȩ��ָ��ɹ�");
	}
	else
	{
		WriteMsgList("���ͻ�ȡ������Ȩ��ָ��ʧ��");
	}
}

void QTieUpPrintTest::on_pushButton_Device_Status_clicked()
{
	m_TieUp->GetDevice_Status();
}

void QTieUpPrintTest::on_pushButton_Ink_Status_clicked()
{
	m_TieUp->GetInk_Status();
}

void QTieUpPrintTest::on_pushButton_Print_clicked()
{
	QString QR_Code = ui.lineEdit_QR_code->text(); //#�Ż���
	QString Text_Code = ui.lineEdit_TEXT_code->text();
	m_TieUp->Print(QR_Code, Text_Code);
}

void QTieUpPrintTest::WriteMsgList(QString msg)
{
	QString time = QDateTime::currentDateTime().toString("hh:mm:ss");
	int count = ui.listWidget->count();
	QListWidgetItem *item = new QListWidgetItem;
	item->setText(time + "   " + msg);
	if (msg != NULL)
	{
		ui.listWidget->insertItem(count + 1, item);
	}
	ui.listWidget->scrollToBottom();
}

void __stdcall QTieUpPrintTest::RcvCallBackEx(int type, QString rcv)
{
	int errType = type;
	WriteMsgList(rcv);
}
