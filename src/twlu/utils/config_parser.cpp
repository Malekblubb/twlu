//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include <twlu/utils/config_parser.h>

#include <mlk/tools/stl_string_utl.h>


namespace twlu
{
	namespace utl
	{
		config_parser::config_parser(const std::string &content) :
			m_config_content{content}
		{this->start_parse();}

		void config_parser::start_parse() noexcept
		{
			this->get_lines();
			this->parse_lines();
		}

		void config_parser::get_lines() noexcept
		{
			// get lines seperatly and store it in vector 'm_lines'
			auto count_n = mlk::stl_string::count_of('\n', m_config_content);
			for(std::size_t i{0}; i <= count_n; ++i)
			{
				std::size_t pos_n{m_config_content.find('\n') + 1};
				m_lines.push_back(std::string{m_config_content.substr(0, pos_n)});
				m_config_content.erase(0, pos_n);
			}
		}

		void config_parser::parse_lines() noexcept
		{
			for(auto& a : m_lines)
				if(!a.empty())
				{
					auto pos_e(a.find('='));
					if(pos_e == std::string::npos)
						continue;

					std::string value{a.substr(pos_e + 1, a.length() - pos_e - 2)};
					mlk::stl_string::erase_all('\"', value);

					m_parsed_lines.push_back(std::make_pair(std::string{a.substr(0, pos_e)},
															value));
				}
		}
	}
}
