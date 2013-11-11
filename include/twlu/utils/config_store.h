//
// Copyright (c) 2013 Christoph Malek
// See LICENSE for more information.
//

#ifndef TWLU_UTILS_CONFIG_STORE_H
#define TWLU_UTILS_CONFIG_STORE_H


#include <twlu/utils/config_entry.h>

#include <memory>
#include <vector>


namespace twlu
{
	namespace utl
	{
		class config_store
		{
			using vec = std::vector<std::shared_ptr<config_entry_base>>;
			vec m_entrys;

		public:
			config_store() = default;

			template<typename T>
			auto add(const config_entry<T>& entry)
			-> std::shared_ptr<config_entry<T>>
			{
				auto a(std::make_shared<config_entry<T>>(entry));
				m_entrys.push_back(a);
				return a;
			}

			int find_name(const std::string& name)
			{
				int index{0};
				for(auto& a : m_entrys)
				{
					if(a->name() == name)
						return index;

					++index;
				}
				return -1;
			}

			template<typename T>
			void set_value(int index, const T& value)
			{std::static_pointer_cast<config_entry<T>>(m_entrys.at(index))->set_value(value);}

			template<typename T>
			T value_at(int index)
			{return std::static_pointer_cast<config_entry<T>>(m_entrys.at(index))->value();}

			const vec& entrys() const noexcept {return m_entrys;}
			std::size_t size() const noexcept {return m_entrys.size();}
		};

		inline config_store make_str_store(const std::vector<std::pair<std::string, std::string>>& pair_vec)
		{
			config_store result;
			for(auto& a : pair_vec)
				result.add(config_entry<std::string>{a.first, a.second});
			return result;
		}

		inline config_store make_str_store(const config_store& store)
		{
			config_store result;
			for(auto& a : store.entrys())
				result.add(config_entry<std::string>{a->name(), a->str_value()});
			return result;
		}
	}
}


#endif // TWLU_UTILS_CONFIG_STORE_H
