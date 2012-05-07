#ifndef OFONO_H
#define OFONO_H

#include <QObject>
#include "ofonomodemmanager.h"
#include "ofonomessagemanager.h"
#include "ofonomodem.h"

class Ofono : public QObject
{
	Q_OBJECT
public:
	Ofono(QObject *parent = 0);

private:
	OfonoModemManager *m_ofonoManager;
	OfonoMessageManager *m_ofonoMessageManager;
	OfonoModem *m_ofonoModem;
    bool m_modemInit;

private slots:
	void on_ofonoManager_modemAdded(const QString&);
	void on_ofonoManager_modemremoved(const QString&);
	void on_ofonoMessageManager_incomingMessage(const QString& message, const QVariantMap& info);
    void on_ofonoModem_poweredChanged(bool powered);
    void on_ofonoModem_onlineChanged(bool online);
};

#endif // OFONO_H
