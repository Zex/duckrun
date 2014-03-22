/*
 * lib/duckrunnet.cpp
 *
 * Author: Zex <top_zlynch@yahoo.com>
 */
#include <QtCore/QDebug>
#include <QtCore/QStringList>
#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <QtGui/QPrinter>
#include <QtGui/QVBoxLayout>
#include <QWebView>
//#include <QUrl>
//#include <NetworkRequest>
//#include <QNetworkReply>
#include "duckrunnet.h"
#include "pdfgentor.h"

duckrunnet::duckrunnet(QWidget *parent)
{
	QRect pgeo;
	if (parent) pgeo = parent->geometry();
	else pgeo = QApplication::desktop()->availableGeometry();

	qDebug() << __PRETTY_FUNCTION__ << "available geometry: " << pgeo;

	setGeometry(QRect(3*pgeo.width()/8, 3*pgeo.height()/8, pgeo.width()/5, pgeo.height()/2));
	setStyleSheet("background-color:black;color:yellow");
	setWindowFlags(Qt::FramelessWindowHint);
	appname = "duckrun";

	qDebug() << __PRETTY_FUNCTION__ << "app geometry: " << this->geometry();

	selftest();
}

void duckrunnet::selftest()
{
	QWebView *wv = new QWebView(this);
	wv->load(QUrl("http://localhost/index.html"));
	QVBoxLayout *wv_vlout = new QVBoxLayout;
	wv_vlout->setContentsMargins(0, 0, 0, 0);
	wv_vlout->addWidget(wv);
	this->setLayout(wv_vlout);
}

//int duckrunnet::run()
//{
//	get_request("/index.html");
//	return 0;
//}
//
//void duckrunnet::req_resp_hdr(const QHttpResponseHeader &resp)
//{
//	qDebug("response protocol-version: http/%d.%d",
//	 resp.majorVersion(), resp.minorVersion());
//	qDebug() << "response status: " << resp.statusCode();
//}
//
//void duckrunnet::req_fini_hdr(int id, bool error)
//{
//	qDebug() << "http id: " << id << "\nhas error: " << error;
//}
//
//int duckrunnet::get_request(QString req)
//{
////	QNetworkReply *rep = duckmgr.get(QNetworkRequest(req));
///*
//	http = new QHttp(this);
//
//	connect(http, SIGNAL(readyRead(QHttpResponseHeader)), this, SLOT(req_resp_hdr(QHttpResponseHeader)));
//	connect(http, SIGNAL(requestFinished(int, bool)), this, SLOT(req_fini_hdr(int, bool)));
//
//	http->setHost("localhost");
//	http->get(req);
//*/
//	return 0;
//}


duckrunnet::~duckrunnet()
{
}


