#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = 0);
	static Database *instance();
signals:

public slots:

private:
	QSqlDatabase db;
	static Database *s_instance;
private:
	bool setValue(const QString& host, const QString& value);
	QString getValue(const QString& host);

signals:
	void valueChanged(const QString& value);
};

#endif // DATABASE_H
