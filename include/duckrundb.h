/*
 * include/duckrundb.h
 *
 * Author: Zex <top_zlynch@yahoo.com>
 */
#ifndef __DUCKRUNDB_H__
#define __DUCKRUNDB_H__

#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtSql/QSqlDatabase>
#include <QtGui/QTextDocument>
#include <QtGui/QWidget>
#include <QtGui/QTableView>

class duckrundb : public QWidget
{
	Q_OBJECT

	QSqlDatabase duckrun;
	QLabel *username_lbl;
	QLineEdit *username_ledit;
	QLabel *passwd_lbl;
	QLineEdit *passwd_ledit;
	QPushButton *login_pbtn;
	QString appname;

//protected:	
//	void add_table_header(const QTableView *res, QString *buf, int col_nr);

public:
	duckrundb(QWidget *parent = 0);
	~duckrundb();
	int run();
	int opendb();
	void selftest();
	void generate_pdf(const QTableView *res);
	QString to_html(const QTableView *res, int line_per_page);
	
public slots:
	int login();
};


#endif /* __DUCKRUNDB_H__ */


