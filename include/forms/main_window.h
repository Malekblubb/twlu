//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef FORMS_MAIN_WINDOW_H
#define FORMS_MAIN_WINDOW_H


#include "ui_main_window.h"

#include <memory>

#include <QMainWindow>


namespace Ui {class main_window;}

namespace twlu
{
	class main_window : public QMainWindow
	{
		Q_OBJECT

		std::unique_ptr<Ui::main_window> m_ui{new Ui::main_window}; // TODO: C++14: std::make_unique

	public:
		explicit main_window(std::unique_ptr<QWidget> parent = nullptr);
		~main_window() = default;
	};
}


#endif // FORMS_MAIN_WINDOW_H
