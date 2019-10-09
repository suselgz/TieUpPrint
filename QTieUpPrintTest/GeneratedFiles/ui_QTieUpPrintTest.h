/********************************************************************************
** Form generated from reading UI file 'QTieUpPrintTest.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTIEUPPRINTTEST_H
#define UI_QTIEUPPRINTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTieUpPrintTestClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Ink_Status;
    QPushButton *pushButton_OpenSerial;
    QPushButton *pushButton_WinccPrivileges;
    QPushButton *pushButton_ScreenPrivileges;
    QPushButton *pushButton_OffSerial;
    QPushButton *pushButton_Device_Status;
    QPushButton *pushButton_Print;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_QR_code;
    QLabel *label_2;
    QLineEdit *lineEdit_TEXT_code;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTieUpPrintTestClass)
    {
        if (QTieUpPrintTestClass->objectName().isEmpty())
            QTieUpPrintTestClass->setObjectName(QStringLiteral("QTieUpPrintTestClass"));
        QTieUpPrintTestClass->resize(600, 400);
        centralWidget = new QWidget(QTieUpPrintTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Ink_Status = new QPushButton(groupBox);
        pushButton_Ink_Status->setObjectName(QStringLiteral("pushButton_Ink_Status"));

        gridLayout->addWidget(pushButton_Ink_Status, 3, 0, 1, 1);

        pushButton_OpenSerial = new QPushButton(groupBox);
        pushButton_OpenSerial->setObjectName(QStringLiteral("pushButton_OpenSerial"));

        gridLayout->addWidget(pushButton_OpenSerial, 0, 0, 1, 1);

        pushButton_WinccPrivileges = new QPushButton(groupBox);
        pushButton_WinccPrivileges->setObjectName(QStringLiteral("pushButton_WinccPrivileges"));

        gridLayout->addWidget(pushButton_WinccPrivileges, 2, 0, 1, 1);

        pushButton_ScreenPrivileges = new QPushButton(groupBox);
        pushButton_ScreenPrivileges->setObjectName(QStringLiteral("pushButton_ScreenPrivileges"));

        gridLayout->addWidget(pushButton_ScreenPrivileges, 2, 1, 1, 1);

        pushButton_OffSerial = new QPushButton(groupBox);
        pushButton_OffSerial->setObjectName(QStringLiteral("pushButton_OffSerial"));

        gridLayout->addWidget(pushButton_OffSerial, 0, 1, 1, 1);

        pushButton_Device_Status = new QPushButton(groupBox);
        pushButton_Device_Status->setObjectName(QStringLiteral("pushButton_Device_Status"));

        gridLayout->addWidget(pushButton_Device_Status, 3, 1, 1, 1);

        pushButton_Print = new QPushButton(groupBox);
        pushButton_Print->setObjectName(QStringLiteral("pushButton_Print"));

        gridLayout->addWidget(pushButton_Print, 4, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit_QR_code = new QLineEdit(groupBox_2);
        lineEdit_QR_code->setObjectName(QStringLiteral("lineEdit_QR_code"));

        gridLayout_2->addWidget(lineEdit_QR_code, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_TEXT_code = new QLineEdit(groupBox_2);
        lineEdit_TEXT_code->setObjectName(QStringLiteral("lineEdit_TEXT_code"));

        gridLayout_2->addWidget(lineEdit_TEXT_code, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addWidget(groupBox_2);

        QTieUpPrintTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTieUpPrintTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        QTieUpPrintTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTieUpPrintTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTieUpPrintTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTieUpPrintTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTieUpPrintTestClass->setStatusBar(statusBar);

        retranslateUi(QTieUpPrintTestClass);

        QMetaObject::connectSlotsByName(QTieUpPrintTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTieUpPrintTestClass)
    {
        QTieUpPrintTestClass->setWindowTitle(QApplication::translate("QTieUpPrintTestClass", "QTieUpPrintTest", 0));
        groupBox->setTitle(QApplication::translate("QTieUpPrintTestClass", "\346\223\215\344\275\234", 0));
        pushButton_Ink_Status->setText(QApplication::translate("QTieUpPrintTestClass", "\345\242\250\347\233\222\347\212\266\346\200\201", 0));
        pushButton_OpenSerial->setText(QApplication::translate("QTieUpPrintTestClass", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        pushButton_WinccPrivileges->setText(QApplication::translate("QTieUpPrintTestClass", "\350\216\267\345\217\226\344\270\212\344\275\215\346\234\272\346\235\203\351\231\220", 0));
        pushButton_ScreenPrivileges->setText(QApplication::translate("QTieUpPrintTestClass", "\350\216\267\345\217\226\346\223\215\344\275\234\345\261\217\346\235\203\351\231\220", 0));
        pushButton_OffSerial->setText(QApplication::translate("QTieUpPrintTestClass", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
        pushButton_Device_Status->setText(QApplication::translate("QTieUpPrintTestClass", "\350\256\276\345\244\207\347\212\266\346\200\201", 0));
        pushButton_Print->setText(QApplication::translate("QTieUpPrintTestClass", "\346\211\223\345\215\260", 0));
        groupBox_2->setTitle(QApplication::translate("QTieUpPrintTestClass", "\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("QTieUpPrintTestClass", "QR_CODE", 0));
        label_2->setText(QApplication::translate("QTieUpPrintTestClass", "TEXT_CODE", 0));
    } // retranslateUi

};

namespace Ui {
    class QTieUpPrintTestClass: public Ui_QTieUpPrintTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTIEUPPRINTTEST_H
