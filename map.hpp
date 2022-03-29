#ifndef __FT_MAP_H__
#define __FT_MAP_H__
#include <memory>
#include "pair.hpp"
#include "iterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>,
        class Alloc = std::allocator<pair<const Key,T> > >
	class map {
		public:
		typedef pair<const Key, T>	value_type;
		typedef Key					key_type;
		typedef T					mapped_type;
		typedef Compare				key_compare;
		typedef Alloc				allocator_type;
	};
}

#endif // __FT_MAP_H__