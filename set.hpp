#ifndef _FT_SET_H__
#define _FT_SET_H__
#include <memory>
#include <functional>
#include "rbt.hpp"

namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
		public:
		typedef T												value_type;
		typedef T												key_type;
		typedef Compare											key_compare;
		typedef Compare											value_compare;
		typedef Alloc											allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef	typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename rb_tree<T, Compare>::iterator			iterator;
		typedef typename rb_tree<T, Compare>::const_iterator	const_iterator;
		typedef const reverse_iterator<iterator>				const_reverse_iterator;
		typedef reverse_iterator<iterator >						reverse_iterator;
		typedef	unsigned long									size_type;
		typedef	ptrdiff_t										difference_type;

		private:
		rb_tree<T, Compare>	_data;
		size_type			_size;
		key_compare			_comp;
		allocator_type		_alloc;

		public:
		set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
		: _data(NULL, comp), _size(0), _comp(comp), _alloc(alloc) {};
		~set() {};

		set& operator=(const set& x) { 
			this->_data = x._data;
			this->_size = x._size;
			this->_comp = x._comp;
			return *this;
		};

	};
}

#endif // __SET_H__