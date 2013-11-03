//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_ERRORS_H
#define TWLU_ERRORS_H


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
			cli_init_error
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
					mlk::lerr.link_error(a.m_code, a.m_msg, a.m_fnc);
			}
		};

		using error_entry = error_s<twlu_errors>;
		static error_inserter e
		{
			error_entry{twlu_errors::cli_init_error, "client initialisation error", []{}}
		};
	}
}


#endif // TWLU_ERRORS_H
