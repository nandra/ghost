#include <QtGui/QApplication>

#include "ofono.h"
#include "webserver.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	new Database();
	new Webserver();
	new Ofono();

    return a.exec();
}

