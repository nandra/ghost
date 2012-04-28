#include "ofono.h"
#include <QDebug>

Ofono::Ofono(QObject *parent)
	: QObject(parent)
{
	m_ofonoManager = new OfonoModemManager();
	connect(m_ofonoManager, SIGNAL(modemAdded(QString)), this, SLOT(on_ofonoManager_modemAdded(QString)));
	connect(m_ofonoManager, SIGNAL(modemRemoved(QString)), this, SLOT(on_ofonoManager_modemremoved(QString)));

	qDebug() << "Available modems:" << m_ofonoManager->modems();

}

void Ofono::on_ofonoManager_modemAdded(const QString &path)
{
	qDebug() << "Modem added:" << path;

	m_ofonoMessageManager = new OfonoMessageManager(OfonoModem::AutomaticSelect, path);
	connect(m_ofonoMessageManager, SIGNAL(incomingMessage(QString,QVariantMap)), this, SLOT(on_ofonoMessageManager_incomingMessage(QString,QVariantMap)));
}

void Ofono::on_ofonoManager_modemremoved(const QString &path)
{
	qDebug() << "Modem removed:" << path;

	disconnect(m_ofonoMessageManager, SIGNAL(incomingMessage(QString,QVariantMap)), 0, 0);
	delete m_ofonoMessageManager;
}

void Ofono::on_ofonoMessageManager_incomingMessage(const QString& message, const QVariantMap& info)
{
	qDebug() << "Message retrieved:" << message << "Info:" << info;
}
