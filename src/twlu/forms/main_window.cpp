//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include "ui_main_window.h"

#include <twlu/forms/main_window.h>


namespace twlu
{
	main_window::main_window(std::shared_ptr<QWidget> parent) :
		QMainWindow{parent.get()}
	{
		m_ui->setupUi(this);

		this->link_signals();
	}

	void main_window::link_signals()
	{

	}

	void main_window::on_m_pb_dev_console_clicked()
	{m_dev_console.show();}
}
