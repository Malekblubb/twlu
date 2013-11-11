//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_UTILS_CONFIG_ENTRY_H
#define TWLU_UTILS_CONFIG_ENTRY_H


#include <mlk/tools/stl_string_utl.h>

#include <memory>
#include <string>


namespace twlu
{
	namespace utl
	{
		template<typename> class config_entry;
		class config_store;

		class config_entry_base
		{
		public:
			config_entry_base() = default;
			virtual ~config_entry_base() = default;

			virtual const std::string& name() const noexcept = 0;
			virtual bool is_str_entry() const noexcept = 0;

			virtual std::string str_value() const noexcept = 0;
		};

		template<typename T>
		class config_entry : public config_entry_base
		{
			std::string m_name;
			T m_value;

		public:
			using type = T;

			config_entry(const std::string& name, const T& value) :
				m_name{name},
				m_value{value}
			{ }
			~config_entry() = default;

			constexpr bool is_str_entry() const noexcept override {return std::is_same<T, std::string>();}
			const std::string& name() const noexcept override {return m_name;}
			const T& value() const noexcept {return m_value;}
			const T& operator()() const noexcept {return m_value;}

			void set_value(const T& value) noexcept {m_value = value;}

			std::string str_value() const noexcept override
			{return mlk::stl_string::to_string(m_value);}
		};

		template<typename T>
		T entry_value(const std::shared_ptr<config_entry_base>& entry_as_base)
		{return std::static_pointer_cast<config_entry<T>>(entry_as_base)->value();}
	}
}



#endif // TWLU_UTILS_CONFIG_ENTRY_H
