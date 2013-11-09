//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_GLOBAL_ERRORS_H
#define TWLU_GLOBAL_ERRORS_H


#include <mlk/log/log.h>

#include <functional>
#include <string>
#include <type_traits>


namespace twlu
{
	namespace global
	{
		enum class twlu_errors
		{
			cli_init_error,
			os_file_create_error
		};


		template<typename T>
		struct error_s
		{
			static_assert(std::is_enum<T>() || std::is_integral<T>(),
						  "integral type required");
			T m_code;
			std::string m_msg;
			std::function<void()> m_fnc;
		};

		class error_inserter
		{
		public:
			template<typename T>
			error_inserter(const std::initializer_list<error_s<T>>& errors)
			{
				for(auto&a : errors)
					mlk::lerr_i().link_error(a.m_code, a.m_msg, a.m_fnc);
			}
		};
	}
}


#endif // TWLU_GLOBAL_ERRORS_H
