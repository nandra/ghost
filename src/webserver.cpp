#include "webserver.h"
#include <QtDebug>

#define REQUEST_PROCESSED ((void *)"yes")
#define REQUEST_NOT_PROCESSED (NULL)

Webserver::Webserver(QObject *parent) :
    QObject(parent)
{
	const char *options[] = {
		"document_root", "www",
		"listening_ports", "8080",
		"num_threads", "5",
		NULL
	};
	// Setup and start Mongoose
	m_context = mg_start(&Webserver::event_handler, NULL, options);
	Q_ASSERT(m_context != NULL);

	qDebug() << "Webserver started...";
}

Webserver::~Webserver()
{
	mg_stop(m_context);
}

void *Webserver::event_handler(enum mg_event event,
						   struct mg_connection *conn,
						   const struct mg_request_info *request_info)
{
	void *processed = NULL;

	if (event == MG_NEW_REQUEST) {
		QString uri(request_info->uri);
		if (uri == "/index.html") {
			if (QString(request_info->query_string) == "modems") {
				mg_printf(conn, "HTTP/1.1 200 OK\r\n"
							  "Content-Type: text/plain\r\n\r\n"
						  "%s", "Any text");
				processed = REQUEST_PROCESSED;
				goto end;
			}
			mg_printf(conn, "HTTP/1.1 302 Found\r\n Location: %s\r\n\r\n"
						  ,request_info->uri);
		}

	}
end:
	return processed;
}
