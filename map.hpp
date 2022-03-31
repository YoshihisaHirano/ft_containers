#ifndef __FT_MAP_H__
#define __FT_MAP_H__
#include <memory>
#include <functional>
#include "pair.hpp"
#include "iterator.hpp"
#include "bst.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>,
        class Alloc = std::allocator<pair<const Key,T> > >
	class map {
		class value_compare : public std::binary_function<pair<const Key, T>, pair<const Key, T>, bool> {
			friend class map;

			protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {};

			public:
			typedef bool				result_type;
			typedef pair<const Key, T>	first_argument_type;
			typedef pair<const Key, T>	second_argument_type;
			bool operator() (const first_argument_type& x, const second_argument_type& y) const
			{
				return comp(x.first, y.first);
			};
		};

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
		typedef typename bs_tree<value_type>::iterator				iterator;
		typedef typename bs_tree<value_type>::const_iterator		const_iterator;
		typedef const reverse_iterator<iterator>					const_reverse_iterator;
		typedef reverse_iterator<iterator >							reverse_iterator;
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
		// template <class InputIterator>
		// map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());
		map(const map& x) : _data(x._data), _size(x._size), _comp(x._comp), _alloc(x._alloc) {};
		map& operator=(const map& x) { 
			this->_data = x._data;
			this->_size = x._size;
			this->_comp = x._comp;
			return *this;
		};

		iterator		begin() { return this->_data.begin(); };
		const_iterator	begin() const { return this->_data.begin(); };
		reverse_iterator rbegin() { return reverse_iterator(this->end()); };
		const_reverse_iterator rbegin() const { return reverse_iterator(this->end()); }; 
		reverse_iterator rend() { return reverse_iterator(this->begin()); };
		const_reverse_iterator rend() const { return reverse_iterator(this->begin()); };;
		iterator		end() { return this->_data.end(); };
		const_iterator	end() const { return this->_data.end(); };
		bool			empty() const { return this->_size == 0; };
		allocator_type	get_allocator() const { return allocator_type(); };
		key_compare		key_comp() const { return key_compare(); };
		size_type		max_size() const { return this->_alloc.max_size(); }; //check with regards to additional data (pointers)
		size_type		size() const { return this->_size; };

		void			clear() { 
			this->_size = 0;
			this->_data.clear();
		};
	};
}

#endif // __FT_MAP_H__