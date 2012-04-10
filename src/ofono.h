#ifndef OFONO_H
#define OFONO_H

#include <QObject>
#include "ofonomodemmanager.h"

class Ofono : public QObject
{
	Q_OBJECT
public:
	Ofono(QObject *parent = 0);

private:
	OfonoModemManager *m_ofonoManager;

private slots:
	void on_ofonoManager_modemAdded(const QString&);
	void on_ofonoManager_modemremoved(const QString&);
};

#endif // OFONO_H
