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
	GET_WINCCPRIVILEGES_SUC=1,  //获得上位机权限
	GET_SCREENPRIVILEGES_SUC=2, //获得操作屏权限
	EQUIPMENT_IDLEING=3,        //设备空闲中
	EQUIPMENT_WORKING = 4,      //设备工作中
	EQUIPMENT_ABNORMAL=5,       //设备异常
	INK_ABNORMAL=6,             //墨盒异常
	INK_NORMAL=7,               //墨盒正常
	PRODUCT_INPLACE=8,          //钱捆就位
	PRINT_END=9                 //扎把打印完成
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
	/*返回信息*/
	virtual void GetlastMsg(int& type,QString& msg)=0;
	/*打开串口*/
	virtual bool OpenSerial(QString portname, int BaudRate, int DataBits, int Parity, int StopBits, RcvTipUpCallBack* hook) = 0;
	/*关闭串口*/
	virtual void OffSerial() = 0;
	/*获取机器权限*/
	virtual bool GetWinccPrivileges() = 0;
	/*获取屏幕权限*/
	virtual bool GetScreenPrivileges() = 0;
	/*获取设备状态*/
	virtual bool GetDevice_Status() = 0;
	/*获取墨盒状态*/
	virtual bool GetInk_Status() = 0;
	/*打印*/
	virtual bool Print(QString QR_Code, QString Text_Code) = 0;
};
CODE_LIB_EXPORT TieupPrint * _stdcall TieupPrintInstance(int version = KX_TIEUPPRINT_VERSION);