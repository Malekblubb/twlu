//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include <twlu/global/errors.h>
#include <twlu/utils/config_file.h>
#include <twlu/utils/config_parser.h>

#include <mlk/log/log.h>


namespace twlu
{
	namespace utl
	{
		config_file::config_file(const std::string& path) :
			m_text_file{path}
		{this->process_file();}


		void config_file::process_file()
		{
			this->read_file();

			if(m_valid)
				this->parse_content();
		}

		void config_file::open_write() noexcept
		{m_text_file.open_io(std::ios::out | std::ios::trunc);}

		void config_file::write_entry(const std::string &name, const std::string &value) noexcept
		{m_text_file.write_line(name + "=" + value);}

		void config_file::read_file()
		{
			if(!m_text_file.exists())
				if(!m_text_file.create()) // create failed
				{
					mlk::lerr(global::twlu_err::os_file_create_error) << "(path=" << m_text_file.path() << ")";
					m_valid = false;
					return;
				}

			m_text_file.open_io(std::ios::in);
			m_text_file.read_all(m_file_content);
			m_valid = true;
		}

		void config_file::parse_content()
		{
			if(m_file_content.empty())
				return;
			m_cp = config_parser{m_file_content};
		}
	}
}
