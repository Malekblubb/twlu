//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include "ui_main_window.h"

#include <forms/main_window.h>


namespace twlu
{
	main_window::main_window(std::unique_ptr<QWidget> parent) :
		QMainWindow{parent.get()}
	{m_ui->setupUi(this);}
}
