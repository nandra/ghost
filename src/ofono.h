#ifndef OFONO_H
#define OFONO_H

#include <QObject>
#include "ofonomodemmanager.h"
#include "ofonomessagemanager.h"

class Ofono : public QObject
{
	Q_OBJECT
public:
	Ofono(QObject *parent = 0);

private:
	OfonoModemManager *m_ofonoManager;
	OfonoMessageManager *m_ofonoMessageManager;

private slots:
	void on_ofonoManager_modemAdded(const QString&);
	void on_ofonoManager_modemremoved(const QString&);
	void on_ofonoMessageManager_incomingMessage(const QString& message, const QVariantMap& info);
};

#endif // OFONO_H
