#ifndef __FT_MAP_H__
#define __FT_MAP_H__
#include <memory>
#include "pair.hpp"
#include "iterator.hpp"
#include "bst.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>,
        class Alloc = std::allocator<pair<const Key,T> > >
	class map {
		public:
		typedef pair<const Key, T>									value_type;
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef Compare												key_compare;
		typedef Alloc												allocator_type;
		typedef	typename allocator_type::reference					reference;
		typedef	typename allocator_type::const_reference			const_reference;
		typedef	typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename bst_iterator<value_type>					iterator;
		typedef const bst_iterator<value_type>						const_iterator;
		typedef const reverse_iterator<bst_iterator<value_type> >	const_reverse_iterator;
		typedef reverse_iterator<bst_iterator<value_type> >			reverse_iterator;
		typedef	unsigned long										size_type;
		typedef	ptrdiff_t											difference_type;

		private:
		bs_tree<value_type>	_data;
		size_type			_size;
		key_compare			_comp;
		allocator_type		_alloc;

		public:
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
		: _data(), _size(0), _comp(comp), _alloc(alloc) {};
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());
		map(const map& x) : _data(x._data), _size(x._size), _comp(x._comp), _alloc(x._alloc) {};
	};
}

#endif // __FT_MAP_H__