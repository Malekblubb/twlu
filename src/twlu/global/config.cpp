//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include <twlu/global/config.h>

#include <mlk/tools/stl_string_utl.h>


namespace twlu
{
	namespace global
	{
		utl::config_store store;
		auto e_check_for_updates(store.add(utl::config_entry<bool>{"cli_check_for_updates", true}));


		int check_for_updates() {return e_check_for_updates->value();}
		void set_check_for_updates(int true_false) {e_check_for_updates->set_value(true_false);}



		config::config(const std::string& path) :
			m_file{path}
		{this->load_user_settings();}

		void config::save_user_settings()
		{
			m_file.open_write();

			utl::config_store tmp_store{utl::make_str_store(store)};
			for(auto& a : tmp_store.entrys())
				m_file.write_entry(a->name(), a->str_value());
		}

		void config::load_user_settings()
		{
			auto user_store = utl::make_str_store(m_file.parsed_lines());
			int i_default{-1};

			for(auto& a : store.entrys())
			{
				++i_default;

				int i_user{user_store.find_name(a->name())};
				if(i_user == -1)
					continue;

				if(a->is_str_entry())
					store.set_value<std::string>(i_default, user_store.value_at<std::string>(i_user));
				else
					store.set_value<int>(i_default, mlk::stl_string::to_int(user_store.value_at<std::string>(i_user)));
			}
		}
	}
}
