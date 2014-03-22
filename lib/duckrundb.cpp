/*
 * lib/duckrundb.cpp
 *
 * Author: Zex <top_zlynch@yahoo.com>
 */
//#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtCore/QStringList>
#include <QtGui/QVBoxLayout>
#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <QtGui/QPixmap>
#include <QFile>
#include <QMessageBox>

#include "pdfgentor.h"
#include "duckrundb.h"

duckrundb::duckrundb(QWidget *parent)
{
	QRect pgeo;
	if (parent) pgeo = parent->geometry();
	else pgeo = QApplication::desktop()->availableGeometry();

	qDebug() << __PRETTY_FUNCTION__ << ": available geometry: " << pgeo;

	setGeometry(QRect(3*pgeo.width()/8, 3*pgeo.height()/8, pgeo.width()/5, pgeo.height()/2));
	setStyleSheet("background-color:black;color:yellow");
	setWindowFlags(Qt::CustomizeWindowHint);
	appname = "duckrun";
	
	qDebug() << __PRETTY_FUNCTION__ << "app geometry: " << this->geometry();

	QLabel *loginimg_lbl = new QLabel(this);
//	QString img_src("/usr/share/duckrun/img/toonvectors-3281-940.jpg");
//	 debugging 
//	if (!QFile(img_src).exists())
//		qDebug() << "couldn't find " << img_src;
	QPixmap greeting_pm("/usr/share/duckrun/img/toonvectors-3281-940.jpg");
	greeting_pm = greeting_pm.scaledToWidth(this->geometry().width());
	loginimg_lbl->setPixmap(greeting_pm);
	
	username_ledit = new QLineEdit(this);
	passwd_ledit = new QLineEdit(this);
	login_pbtn = new QPushButton(tr("Login"), this);

	QVBoxLayout *login_vlout = new QVBoxLayout;
	login_vlout->addWidget(loginimg_lbl);
	login_vlout->addStretch();
	login_vlout->addWidget(username_ledit);
	login_vlout->addWidget(passwd_ledit);
	login_vlout->addWidget(login_pbtn);

	login_vlout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(login_vlout);

	username_ledit->setPlaceholderText(tr("Username"));
	passwd_ledit->setEchoMode(QLineEdit::Password);
	passwd_ledit->setPlaceholderText(tr("Password"));

	connect(login_pbtn, SIGNAL(clicked()), this, SLOT(login()));
	connect(username_ledit, SIGNAL(returnPressed()), this, SLOT(login()));
	connect(passwd_ledit, SIGNAL(returnPressed()), this, SLOT(login()));

/*
	qDebug() << "availible db drivers:";

	int i = 1;
	foreach (const QString &s, QSqlDatabase::drivers()) {
		qDebug("%s%s", s.toStdString().c_str(), !(i++%5)?"\n":" ");
	}
*/
}

int duckrundb::login()
{
	if (username_ledit->text().isEmpty() ||
		passwd_ledit->text().isEmpty()) {
		qDebug() << "empty username and/or password";
		return -1;
	}

	login_pbtn->setEnabled(false);

	duckrun = QSqlDatabase::addDatabase("QMYSQL");
//	duckrun = QSqlDatabase::database("duckrun");
	duckrun.setHostName("localhost");
	duckrun.setPort(3306);
	duckrun.setDatabaseName(appname);
	duckrun.setUserName(username_ledit->text());//"duckadm");
	duckrun.setPassword(passwd_ledit->text());//"riskcud");

	qDebug() << "username: " << username_ledit->text();
	qDebug() << "passwd: " << passwd_ledit->text();
	qDebug() << "duckrun db is valid: " << duckrun.isValid();
	qDebug() << "duckrun db hostname: " << duckrun.hostName();	
	qDebug() << "duckrun db name: " << duckrun.databaseName();	
	qDebug() << "duckrun db username: " << duckrun.userName();	
	qDebug() << "duckrun db port: " << duckrun.port();
	qDebug() << "duckrun db driver: " << duckrun.driver();

	if (opendb()) {
		QMessageBox::warning(this, appname, "no such user or wrong password");
		login_pbtn->setEnabled(true);
	} else {
		disconnect(login_pbtn, SIGNAL(clicked()), this, SLOT(login()));
		disconnect(username_ledit, SIGNAL(returnPressed()), this, SLOT(login()));
		disconnect(passwd_ledit, SIGNAL(returnPressed()), this, SLOT(login()));
		selftest();
	}

	return 0;
}

int duckrundb::opendb()
{
	if (!duckrun.open()) {
		qDebug() << "failed to open duckrun db";
		duckrun.setConnectOptions();
		return -1;
	}

	return 0;
}

void duckrundb::selftest()
{
	QSqlQueryModel *q = new QSqlQueryModel;
	q->setQuery("select * from duckinfo");
	q->setHeaderData(0, Qt::Horizontal, tr("Email"));
	q->setHeaderData(1, Qt::Horizontal, tr("Birth Day"));
	q->setHeaderData(2, Qt::Horizontal, tr("Class"));

	QVBoxLayout *res_vlout = new QVBoxLayout;
	QTableView *res = new QTableView(this);
	res->setStyleSheet("QHeaderView::section { background-color:darkblue }");
	res->setModel(q);
	res->verticalHeader()->hide();
	res->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
	res_vlout->addWidget(res);
	res_vlout->setContentsMargins(0, 0, 0, 0);

	delete this->layout();
	this->setLayout(res_vlout);

	pdfgentor(appname).generate(res);
}

duckrundb::~duckrundb()
{
	duckrun.close();
	QSqlDatabase::removeDatabase(appname);
}

