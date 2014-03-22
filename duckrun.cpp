#include <QtGui/QApplication>
#include "duckrundb.h"
#include "duckrunnet.h"

int main(int argc, char* argv[])
{
	QApplication qapp(argc, argv);
	duckrundb db;
	duckrunnet net;

	net.show();
	db.show();

	return qapp.exec();
}
