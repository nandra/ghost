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
}

void Ofono::on_ofonoManager_modemremoved(const QString &path)
{
	qDebug() << "Modem removed:" << path;
}
