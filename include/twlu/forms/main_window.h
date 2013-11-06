//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_FORMS_MAIN_WINDOW_H
#define TWLU_FORMS_MAIN_WINDOW_H


#include "ui_main_window.h"

#include <twlu/forms/dev_console.h>

#include <memory>

#include <QMainWindow>


namespace Ui {class main_window;}

namespace twlu
{
	class main_window : public QMainWindow
	{
		Q_OBJECT

		// ui
		std::unique_ptr<Ui::main_window> m_ui{new Ui::main_window}; // TODO: C++14: std::make_unique

		// ui classes
		dev_console m_dev_console;

	public slots:
		void on_m_pb_dev_console_clicked();

	public:
		explicit main_window(std::shared_ptr<QWidget> parent = nullptr);
		~main_window() = default;

	private:
		void link_signals();
	};
}


#endif // TWLU_FORMS_MAIN_WINDOW_H
