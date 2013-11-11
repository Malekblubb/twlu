//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include <twlu/forms/main_window.h>

#include <QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	twlu::main_window w;
	w.show();

	return a.exec();
}
