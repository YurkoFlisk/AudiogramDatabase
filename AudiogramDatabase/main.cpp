#include "AudiogramDatabase.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AudiogramDatabase w;
	w.show();
	return a.exec();
}
