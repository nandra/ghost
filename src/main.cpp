#include <QtGui/QApplication>

#include "ofono.h"
#include "webserver.h"
#include "database.h"
#include <fstream>
#include <QTime>

using namespace std;
ofstream logfile;

void SimpleLoggingHandler(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Debug: " << msg << "\n";
        fprintf(stderr, "%s [DEBUG]: %s\n", QTime::currentTime().toString().toAscii().data(), msg);
        break;
    case QtCriticalMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Critical: " << msg << "\n";
        fprintf(stderr, "%s [CRITICAL]: %s\n", QTime::currentTime().toString().toAscii().data(), msg);
        break;
    case QtWarningMsg:
        logfile << QTime::currentTime().toString().toAscii().data() << " Warning: " << msg << "\n";
        fprintf(stderr, "%s [WARN]: %s\n", QTime::currentTime().toString().toAscii().data(), msg);
        break;
    case QtFatalMsg:
        logfile << QTime::currentTime().toString().toAscii().data() <<  " Fatal: " << msg << "\n";
        fprintf(stderr, "%s [FATAL]: %s\n", QTime::currentTime().toString().toAscii().data(), msg);
        abort();
    }

    logfile.flush();
 }

int main(int argc, char *argv[])
{
    if (argc > 1) {
        // argument 1 is logfile for logging
        logfile.open(argv[1], ios::app);
    }

    qInstallMsgHandler(SimpleLoggingHandler);

    QApplication a(argc, argv);

	new Database();
	new Webserver();
	new Ofono();

    return a.exec();
}

