//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_UTILS_CONFIG_FILE_H
#define TWLU_UTILS_CONFIG_FILE_H


#include "config_parser.h"

#include <mlk/filesystem/filesystem.h>


namespace twlu
{
	namespace utl
	{
		class config_file
		{
			mlk::fs::fs_handle<mlk::fs::fs_type::file> m_text_file;
			config_parser m_cp;
			std::string m_file_content;
			bool m_valid{false};

		public:
			config_file(const std::string& path);

			bool exists() const noexcept {return m_text_file.exists();}

			auto parsed_lines() const noexcept
			-> decltype(m_cp.parsed_lines())
			{return m_cp.parsed_lines();}

			void open_write() noexcept;
			void write_entry(const std::string& name, const std::string& value) noexcept;

		private:
			void process_file();
			void read_file();
			void parse_content();
		};
	}
}

#endif // TWLU_UTILS_CONFIG_FILE_H
