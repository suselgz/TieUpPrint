#define KX_TIEUPPRINT_MAIN_VERSION 1
#define KX_TIEUPPRINT_SUB_VERSION 1
#define KX_TIEUPPRINT_VERSION ((KX_TIEUPPRINT_MAIN_VERSION << 16) + KX_TIEUPPRINT_SUB_VERSION)
#pragma once
#include <QObject>
#define CODE_LIB_SOLUTION
#ifdef  CODE_LIB_SOLUTION
#define CODE_LIB_EXPORT __declspec(dllexport)
#else
#define CODE_LIB_EXPORT __declspec(dllimport)
#endif

enum RECALL_MSGFROM_TIE
{
	GET_WINCCPRIVILEGES_SUC=1,  //�����λ��Ȩ��
	GET_SCREENPRIVILEGES_SUC=2, //��ò�����Ȩ��
	EQUIPMENT_IDLEING=3,        //�豸������
	EQUIPMENT_WORKING = 4,      //�豸������
	EQUIPMENT_ABNORMAL=5,       //�豸�쳣
	INK_ABNORMAL=6,             //ī���쳣
	INK_NORMAL=7,               //ī������
	PRODUCT_INPLACE=8,          //Ǯ����λ
	PRINT_END=9                 //���Ѵ�ӡ���
};
class  RcvTipUpCallBack
{
public:
	virtual void __stdcall RcvCallBackEx(int type,QString rcv) = 0;
};
class  TieupPrint : public QObject
{
	Q_OBJECT
public:
	/*������Ϣ*/
	virtual void GetlastMsg(int& type,QString& msg)=0;
	/*�򿪴���*/
	virtual bool OpenSerial(QString portname, int BaudRate, int DataBits, int Parity, int StopBits, RcvTipUpCallBack* hook) = 0;
	/*�رմ���*/
	virtual void OffSerial() = 0;
	/*��ȡ����Ȩ��*/
	virtual bool GetWinccPrivileges() = 0;
	/*��ȡ��ĻȨ��*/
	virtual bool GetScreenPrivileges() = 0;
	/*��ȡ�豸״̬*/
	virtual bool GetDevice_Status() = 0;
	/*��ȡī��״̬*/
	virtual bool GetInk_Status() = 0;
	/*��ӡ*/
	virtual bool Print(QString QR_Code, QString Text_Code) = 0;
};
CODE_LIB_EXPORT TieupPrint * _stdcall TieupPrintInstance(int version = KX_TIEUPPRINT_VERSION);