//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include "ui_dev_console.h"

#include <twlu/forms/dev_console.h>

#include <mlk/log/log.h>


namespace twlu
{
	dev_console::dev_console(std::shared_ptr<QWidget> parent) :
		QWidget{parent.get()}
	{
		m_ui->setupUi(this);

		// slots
		m_refresh_log += [this](const std::string& last_entry){this->refresh_log(last_entry);};

		// links
		mlk::link_signal(mlk::lout().m_entry_added, m_refresh_log);
	}

	void dev_console::refresh_log(const std::string& last_entry)
	{m_ui->m_te_log->insertPlainText(last_entry.c_str()); m_ui->m_te_log->ensureCursorVisible();}
}
