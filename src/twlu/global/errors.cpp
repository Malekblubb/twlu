//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#include <twlu/global/errors.h>


namespace twlu
{
	namespace global
	{
		using error_entry = error_s<twlu_err>;
		static error_inserter e
		{
			error_entry{twlu_err::cli_init_error, "client initialisation error", []{}},
			error_entry{twlu_err::os_file_create_error, "error while create file", []{}}
		};
	}
}
