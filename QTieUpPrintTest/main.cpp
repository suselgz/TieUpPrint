#include "QTieUpPrintTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTieUpPrintTest w;
	w.show();
	return a.exec();
}
