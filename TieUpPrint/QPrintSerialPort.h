#pragma once
//#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTextCodec>
#include "TieupPrint.h"

class QPrintSerialPort : public TieupPrint
{
//	Q_OBJECT
//signals :
//	void SendDataToOnlineUI(QString);
public:
	QPrintSerialPort();
	~QPrintSerialPort();
	bool OpenSerial(QString portname, int BaudRate, int DataBits, int Parity, int StopBits, RcvTipUpCallBack* hook);
	void OffSerial();	
	bool GetWinccPrivileges();	
	bool GetScreenPrivileges();	
	bool GetDevice_Status();	
	bool GetInk_Status();
	bool Print(QString QR_Code, QString Text_Code);
private:
	RcvTipUpCallBack*  m_hook;
	QSerialPort *m_serial;
	int m_msgType;
	bool SendData(QString str);
	void ReadData();
	void RevSerialPortData(QString rev, QString& ret, int& type);
	QByteArray QString2Hex(QString str);
	char ConvertHexChar(char ch);
	QString ByteArrayToHexString(QByteArray data);
	int ConvertQStringtoASCII(QString str);
	QString QStringtoHex(const QString &inStr);
};
