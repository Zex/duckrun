/*
 * include/pdfgentor.h
 *
 * Author: Zex <top_zlynch@yahoo.com>
 */
#ifndef __PDFGENTOR_H__
#define __PDFGENTOR_H__

#include <QtCore/QDebug>
#include <QtSql/QSqlQueryModel>
#include <QtGui/QTextDocument>
#include <QtGui/QTableView>
#include <QtCore/QDateTime>
#include <QtGui/qheaderview.h>
#include <QtGui/QPrinter>

class pdfgentor
{
QString appname;

protected:	
void add_table_header(const QTableView *res, QString *buf, int col_nr);

public:
pdfgentor(QString appname);
~pdfgentor() {}
QString to_html(const QTableView *res, int line_per_page);
void generate(const QTableView *res);

};

#endif /* __PDFGENTOR_H__ */


