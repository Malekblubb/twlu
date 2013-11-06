//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_FORMS_DEV_CONSOLE_H
#define TWLU_FORMS_DEV_CONSOLE_H


#include "ui_dev_console.h"

#include <mlk/signals_slots/slot.h>

#include <memory>
#include <string>

#include <QWidget>


namespace Ui {class dev_console;}

namespace twlu
{
	class dev_console : public QWidget
	{
		Q_OBJECT

		std::unique_ptr<Ui::dev_console> m_ui{new Ui::dev_console};


	public:
		// slots
		mlk::slot<void(const std::string&)> m_refresh_log;


		explicit dev_console(std::shared_ptr<QWidget> parent = nullptr);
		~dev_console() = default;


		void refresh_log(const std::string &last_entry);
	};
}


#endif // TWLU_FORMS_DEV_CONSOLE_H
