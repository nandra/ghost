#include <QtGui/QApplication>

#include "ofono.h"
#include "webserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	new Webserver();
	new Ofono();

    return a.exec();
}

