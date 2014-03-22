/*
 * include/duckrunnet.H
 *
 * Author: Zex <top_zlynch@yahoo.com>
 */
#ifndef __DUCKRUNNET_H__
#define __DUCKRUNNET_H__

//#include <QtSql/QSqlDatabase>
//#include <QNetworkAccessManager>
#include <QtNetwork/QHttp>
#include <QtGui/QWidget>

class duckrunnet : public QWidget
{
	Q_OBJECT
//QSqlDatabase duckrun;
//QNetworkAccessManager duckmgr;
	QString appname;
//	QHttp *http;

public:
	duckrunnet(QWidget *parent = 0);
	~duckrunnet();
	void selftest();
//	int run();
//	int get_request(QString req);
//	
//public slots:
//	void req_fini_hdr(int id, bool error);
//	void req_resp_hdr(const QHttpResponseHeader &resp);
};


#endif /* __DUCKRUNNET_H__ */


