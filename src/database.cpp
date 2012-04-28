#include "database.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QVariant>

#define DEBUG_LINE(fmt...) qDebug() << "Error on line:" << __LINE__ << fmt;

Database *Database::s_instance = NULL;

Database *Database::instance()
{
	if (s_instance == NULL)
		s_instance = new Database();

	return s_instance;
}

Database::Database(QObject *parent) :
    QObject(parent)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("../../db/test.db");
	bool ok = db.open();
	qDebug() << "Open database" << ok;

	if (!ok)
		return;

	QSqlQuery query = db.exec("create temp table if not exists paths_temp(path TEXT, value TEXT);");
	if (query.lastError().isValid())
		 qDebug() << query.lastError();

}

bool Database::setValue(const QString& host, const QString& value)
{
	QStringList data = host.split("://");
	QString table = data.at(0);
	QString path = data.at(1);
	if (table.isEmpty()) {
		qDebug() << "Non existing table";
		return false;
	}

	QString dta;
	if (getValue(host).isEmpty()) {
		dta = QString("INSERT INTO %1 (path, value) VALUES('%2','%3')").arg(table).arg(path).arg(value);
	} else {
		dta = QString("UPDATE %1 SET path='%2',value='%3'").arg(table).arg(path).arg(value);
	}
	QSqlQuery query(dta);
	if (!query.exec()) {
		DEBUG_LINE(query.lastError());
		return false;
	}

	return true;
}

QString Database::getValue(const QString& host)
{
	// path is in format: table_name://path
	QStringList data = host.split("://");

	QString table = data.at(0);
	QString path = data.at(1);
	if (table.isEmpty()) {
		qDebug() << "Non existing table";
		return false;
	}

	QString dta = QString("SELECT value FROM %1 WHERE path='%2'").arg(table).arg(path);
	QSqlQuery query(dta);
	QString value;
	while (query.next()) {
		value = query.value(0).toString();
	}

	return value;
}

