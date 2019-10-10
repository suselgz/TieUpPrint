#include "QPrintSerialPort.h"
#pragma execution_character_set("utf-8")
QPrintSerialPort::QPrintSerialPort()
{
	m_serial = new QSerialPort;
	m_msgType = -1;
}

QPrintSerialPort::~QPrintSerialPort()
{
	OffSerial();
	delete m_serial;
}

bool QPrintSerialPort::OpenSerial(QString portname, int BaudRate, int DataBits, int Parity, int StopBits, RcvTipUpCallBack* hook)
{
	m_hook = hook;
	bool nRet = true;
	//设置串口名
	m_serial->setPortName(portname);
	//打开串口
	if (!m_serial->open(QIODevice::ReadWrite))
	{
		nRet = false;
	}
	//设置波特率
	if (!m_serial->setBaudRate(BaudRate))
	{
		nRet = false;
	}
	//设置数据位数
	switch (DataBits)
	{
	case 8:
		m_serial->setDataBits(QSerialPort::Data8);//设置数据位8
		break;
	default:
		break;
	}
	//设置校验位
	switch (Parity)
	{
	case 0:
		m_serial->setParity(QSerialPort::NoParity);
		break;
	default:
		break;
	}
	//设置停止位
	switch (StopBits)
	{
	case 1:
		m_serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
		break;
	case 2:
		m_serial->setStopBits(QSerialPort::TwoStop);
	default:
		break;
	}
	//设置流控制
	if (!m_serial->setFlowControl(QSerialPort::NoFlowControl))//设置为无流控制
	{
		nRet = false;
	}
	//连接信号槽
	connect(m_serial, &QSerialPort::readyRead, this, &QPrintSerialPort::ReadData);
	return nRet;
}

void QPrintSerialPort::OffSerial()
{
	if (m_serial->isOpen())
	{
		//关闭串口
		m_serial->clear();
		m_serial->close();
		m_serial->deleteLater();
	}

}

bool QPrintSerialPort::GetWinccPrivileges()
{
	QString str = "0xAB 01 01 1A";
	bool nRnt = SendData(str);
	return nRnt;
}
bool QPrintSerialPort::GetScreenPrivileges()
{
	QString str = "0xAB 01 00 1A";
	bool nRnt = SendData(str);
	return nRnt;
}

bool QPrintSerialPort::GetDevice_Status()
{
	QString str = "0xAB 03 01 1A";
	bool nRnt = SendData(str);
	return nRnt;
}

bool QPrintSerialPort::GetInk_Status()
{
	QString str = "AB 04 01 1A";
	bool nRnt = SendData(str);
	return nRnt;
}

bool QPrintSerialPort::Print(QString QR_Code, QString Text_Code)
{
	QString QR_Code_Hex;
	for (int i = 0; i < QR_Code.length(); i++)
	{
		QString C;
		if (QR_Code.at(i) == "#")
		{
			C = "09";
		}
		else
		{
			C = QStringtoHex(QR_Code.at(i));
		}
		QR_Code_Hex += C;
	}
	QString Text_Code_Hex;
	for (int i = 0; i < Text_Code.length(); i++)
	{
		QString C;
		if (Text_Code.at(i) == "#")
		{
			C = "09";
		}
		else
		{
			C = QStringtoHex(Text_Code.at(i));
		}
		Text_Code_Hex += C;
	}
//	QString Text_Code_Hex = QStringtoHex(Text_Code);
	int Qlen = QR_Code_Hex.length() / 2;
	int Tlen = Text_Code_Hex.length() / 2;
	QString head = "AB0206"; //信息头
	QString total_len = QString("%1").arg(Qlen + Tlen + 2, 2, 16, QLatin1Char('0'));//总长度=信息长度+2位
	QString QR_len = QString("%1").arg(Qlen, 2, 16, QLatin1Char('0'));//QR_长度
	QString t = QString("%1").arg(Tlen);
	int a1 = ConvertQStringtoASCII(t);
	QString Text_len = QString("%1").arg(a1, 2, 16, QLatin1Char('0')); //Text_长度
	QString print = head + total_len + QR_len + QR_Code_Hex + Text_len + Text_Code_Hex;
	print = print.trimmed();
	bool nRnt = SendData(print);
	return nRnt;
}

void QPrintSerialPort::ReadData()
{
	QByteArray buf;
	QString strData = "";
	buf = m_serial->readAll();
	if (!buf.isEmpty())
	{
		strData = ByteArrayToHexString(buf);
	}
	int type = -1;
	QString rcv;
	RevSerialPortData(strData,rcv,type);
	m_hook->RcvCallBackEx(type, rcv);
	buf.clear();
}
void QPrintSerialPort::RevSerialPortData(QString rev,QString& ret,int& type)
{
	if (rev == "5B 01 01 1B")
	{
		ret="已获得上位机权限";
		type = RECALL_MSGFROM_TIE::GET_WINCCPRIVILEGES_SUC;
	}
	if (rev == "5B 01 00 1B")
	{
		ret = "已获得操作屏权限";
		type = RECALL_MSGFROM_TIE::GET_SCREENPRIVILEGES_SUC;
	}
	if (rev.mid(0, 5) == "5B 03")
	{
		QString str = rev.mid(6, 2);
		if (str == "01")
		{
			ret = "设备空闲中";
			type = RECALL_MSGFROM_TIE::EQUIPMENT_IDLEING;
		}
		if (str == "02")
		{
			ret = "设备工作中";
			type = RECALL_MSGFROM_TIE::EQUIPMENT_WORKING;
		}
		if (str == "03")
		{
			ret = "设备异常";
			type = RECALL_MSGFROM_TIE::EQUIPMENT_ABNORMAL;
		}
	}
	if (rev.mid(0, 5) == "5B 04")
	{
		QString str = rev.mid(6, 2);
		if (str == "00")
		{
			ret = "墨盒异常";
			type = RECALL_MSGFROM_TIE::INK_ABNORMAL;
		}
		if (str == "01")
		{
			ret = "墨盒正常";
			type = RECALL_MSGFROM_TIE::INK_NORMAL;
		}
	}
	if (rev.mid(0, 5) == "5B 05")
	{
		QString str = rev.mid(6, 2);
		if (str == "01")
		{
			ret = "钱捆就位";
			type = RECALL_MSGFROM_TIE::PRODUCT_INPLACE;
		}
	}
	if (rev.mid(0, 5) == "5B 06")
	{
		QString str = rev.mid(6, 2);
		if (str == "01")
		{
			ret = "扎把打印完成";
			type = RECALL_MSGFROM_TIE::PRINT_END;
		}
	}
}
bool QPrintSerialPort::SendData(QString str)
{

	if (!m_serial->isOpen())
	{
		return false;
	}
	QByteArray array;
	array = QString2Hex(str);
	qint64 serial = m_serial->write(array);
	return true;
}
QByteArray QPrintSerialPort::QString2Hex(QString str)
{
	QByteArray senddata;
	int hexdata, lowhexdata;
	int hexdatalen = 0;
	int len = str.length();
	senddata.resize(len / 2);
	char lstr, hstr;
	for (int i = 0; i < len;)
	{
		hstr = str[i].toLatin1();
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)
			break;
		lstr = str[i].toLatin1();
		hexdata = ConvertHexChar(hstr);
		lowhexdata = ConvertHexChar(lstr);
		if ((hexdata == 16) || (lowhexdata == 16))
			break;
		else
			hexdata = hexdata * 16 + lowhexdata;
		i++;
		senddata[hexdatalen] = (char)hexdata;
		hexdatalen++;
	}
	senddata.resize(hexdatalen);
	return senddata;
}
char QPrintSerialPort::ConvertHexChar(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return ch - 0x30;
	else if ((ch >= 'A') && (ch <= 'F'))
		return ch - 'A' + 10;
	else if ((ch >= 'a') && (ch <= 'f'))
		return ch - 'a' + 10;
	else return (-1);
}
QString QPrintSerialPort::ByteArrayToHexString(QByteArray data)
{
	QString ret(data.toHex().toUpper());
	int len = ret.length() / 2;
	for (int i = 1; i < len; i++)
	{
		ret.insert(2 * i + i - 1, " ");
	}
	return ret;
}

int QPrintSerialPort::ConvertQStringtoASCII(QString str)
{
	QByteArray byte = str.toUtf8();
	return byte.at(0);
}
QString QPrintSerialPort::QStringtoHex(const QString &inStr)
{
	return inStr.toLocal8Bit().toHex().toUpper();
}
TieupPrint * _stdcall TieupPrintInstance(int version)
{
	if (version == KX_TIEUPPRINT_VERSION)
	{
		TieupPrint *Tie;
		Tie = (TieupPrint *)new QPrintSerialPort;
		return Tie;
	}
	else
	{
		return 0;
	}
}
