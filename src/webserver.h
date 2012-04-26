#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QObject>
#include "mongoose.h"

class Webserver : public QObject
{
    Q_OBJECT
public:
    explicit Webserver(QObject *parent = 0);
	~Webserver();
	static void *event_handler(enum mg_event event,
										  struct mg_connection *conn,
										  const struct mg_request_info *request_info);
signals:

public slots:

private:
	struct mg_context *m_context;

};

#endif // WEBSERVER_H
