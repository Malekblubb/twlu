//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_GLOBAL_CONFIG_H
#define TWLU_GLOBAL_CONFIG_H


#include <twlu/utils/config_entry.h>
#include <twlu/utils/config_file.h>
#include <twlu/utils/config_store.h>


namespace twlu
{
	namespace global
	{
		// config entry getters/setters
		int check_for_updates();
		void set_check_for_updates(int true_false);

		// global config interface
		bool save_config();


		class config
		{
			utl::config_file m_file;

		public:
			config(const std::string& path);

			void save_user_settings();

		private:
			void load_user_settings();
		};
	}
}


#endif // TWLU_GLOBAL_CONFIG_H
