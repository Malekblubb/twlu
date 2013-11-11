//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_UTILS_CONFIG_PARSER_H
#define TWLU_UTILS_CONFIG_PARSER_H


#include <string>
#include <vector>


namespace twlu
{
	namespace utl
	{
		class config_parser
		{
			std::vector<std::string> m_lines;
			std::vector<std::pair<std::string, std::string>> m_parsed_lines;
			std::string m_config_content;

		public:
			config_parser() = default;
			config_parser(const std::string& content);

			auto parsed_lines() const noexcept
			-> const std::vector<std::pair<std::string, std::string>>&
			{return m_parsed_lines;}
			std::size_t num_settings() const noexcept {return m_parsed_lines.size();}

		private:
			void start_parse() noexcept;
			void get_lines() noexcept;
			void parse_lines() noexcept;
		};
	}
}


#endif // TWLU_UTILS_CONFIG_PARSER_H
