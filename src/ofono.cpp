#include "ofono.h"
#include <QDebug>
#include <QStringList>

Ofono::Ofono(QObject *parent)
	: QObject(parent)
    , m_modemInit(false)
{
	m_ofonoManager = new OfonoModemManager();
	connect(m_ofonoManager, SIGNAL(modemAdded(QString)), this, SLOT(on_ofonoManager_modemAdded(QString)));
	connect(m_ofonoManager, SIGNAL(modemRemoved(QString)), this, SLOT(on_ofonoManager_modemremoved(QString)));

	qDebug() << "Available modems:" << m_ofonoManager->modems();
	if (!m_ofonoManager->modems().isEmpty())
		on_ofonoManager_modemAdded(m_ofonoManager->modems().at(0));
}

void Ofono::on_ofonoManager_modemAdded(const QString &path)
{
	qDebug() << "Modem added:" << path;

	m_ofonoMessageManager = new OfonoMessageManager(OfonoModem::AutomaticSelect, path);
	connect(m_ofonoMessageManager, SIGNAL(incomingMessage(QString,QVariantMap)), this, SLOT(on_ofonoMessageManager_incomingMessage(QString,QVariantMap)));

	/* Enable modem by default */
	m_ofonoModem = new OfonoModem(OfonoModem::ManualSelect, path);
    connect(m_ofonoModem, SIGNAL(poweredChanged(bool)), this, SLOT(on_ofonoModem_poweredChanged(bool)));
    connect(m_ofonoModem, SIGNAL(onlineChanged(bool)), this, SLOT(on_ofonoModem_onlineChanged(bool)));

    if (!m_ofonoModem->powered()) {
		m_ofonoModem->setPowered(true);
    }
}

void Ofono::on_ofonoManager_modemremoved(const QString &path)
{
	qDebug() << "Modem removed:" << path;

	disconnect(m_ofonoMessageManager, SIGNAL(incomingMessage(QString,QVariantMap)), 0, 0);
	delete m_ofonoMessageManager;

	delete m_ofonoModem;
    m_modemInit = false;
}

void Ofono::on_ofonoMessageManager_incomingMessage(const QString& message, const QVariantMap& info)
{
	qDebug() << "Message retrieved:" << message << "Info:" << info;
}

void Ofono::on_ofonoModem_poweredChanged(bool powered)
{
    if (!powered) {
        qDebug() << __func__ << "powered failed";
        return;
    }

    if (!m_ofonoModem->online())
        m_ofonoModem->setOnline(true);
}

void Ofono::on_ofonoModem_onlineChanged(bool online)
{
    if (!online) {
        qDebug() << __func__ << "online failed";
        return;
    }

    qDebug() << "Modem powered & online.";

    m_modemInit = true;
}
