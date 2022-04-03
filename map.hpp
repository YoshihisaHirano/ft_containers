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
		typedef typename bs_tree<value_type, value_compare>::iterator				iterator;
		typedef typename bs_tree<value_type, value_compare>::const_iterator		const_iterator;
		typedef const reverse_iterator<iterator>					const_reverse_iterator;
		typedef reverse_iterator<iterator >							reverse_iterator;
		typedef	unsigned long										size_type;
		typedef	ptrdiff_t											difference_type;

		private:
		bs_tree<value_type, value_compare>	_data;
		size_type							_size;
		key_compare							_comp;
		allocator_type						_alloc;

		public:
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
		: _data(NULL, value_compare(comp)), _size(0), _comp(comp), _alloc(alloc) {};

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) 
		: _data(NULL, value_compare(comp)), _size(0), _comp(comp), _alloc(alloc) { 
			this->insert(first, last);
		};

		map(const map& x) : _data(NULL, value_compare(x._comp)), _size(0), _comp(x._comp), _alloc(x._alloc) {
			this->insert(x.begin(), x.end());
		};

		~map() {
			this->clear();
		};

		map& operator=(const map& x) { 
			this->_data = x._data;
			this->_size = x._size;
			this->_comp = x._comp;
			return *this;
		};

		mapped_type& operator[] (const key_type& k) {
			return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
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
		value_compare	value_comp() const { return value_compare(key_compare()); };
		size_type		max_size() const { return this->_data.max_size(); };
		size_type		size() const { return this->_size; };

		void			clear() { 
			this->_size = 0;
			this->_data.clear();
		};

		iterator		find(const key_type& k) { 
			pair<key_type, mapped_type> val(k, mapped_type());
			iterator it = this->_data.find(val);
			return it;
		};

		const_iterator	find(const key_type& k) const { 
			pair<key_type, mapped_type> val(k, mapped_type());
			const_iterator it = this->_data.find(val);
			return it;
		};

		size_type		count(const key_type& k) const {
			return (this->find(k) == this->_data.end()) ? 0 : 1;
		};

		pair<iterator,bool>	insert(const value_type& val) { 
			iterator it = this->_data.insert(val);
			if (it == this->end())
				return pair<iterator,bool>(it, false);
			this->_size++;
			return pair<iterator,bool>(it, true);
		};

		iterator		insert(iterator position, const value_type& val) {
			(void)position;
			return this->insert(val).first;
		};

		template <class InputIterator>
		void		insert(InputIterator first, InputIterator last) {
			for (; first != last; ++first)
				this->insert(*first);
		};

		iterator		lower_bound (const key_type& k) { 
			iterator it = this->find(k);
			if (it != this->end())
				return it;
			for (it = this->begin(); it != this->end(); ++it) {
				if (!this->_comp(it->first, k))
					break;
			}
			return it;
		};

		const_iterator	lower_bound (const key_type& k) const { 
			return const_iterator(this->lower_bound(k));
		};

		iterator		upper_bound (const key_type& k) {
			iterator it = this->begin();
			for (; it != this->end(); ++it) {
				if (this->_comp(k, it->first))
					break;
			}
			return it;
		};

		const_iterator	upper_bound (const key_type& k) const { 
			return const_iterator(this->upper_bound(k));
		};

		void			erase (iterator position) {
			this->_data.remove(*position);
			this->_size--;
		};

		size_type		erase (const key_type& k) {
			iterator it = this->find(k);
			std::cout << "key: " << k << std::endl;
			if (it == this->end())
				return 0;
			this->_data.remove(*it);
			this->_size--;
			return 1;
		};

		void			erase (iterator first, iterator last) {
			while (first != last)
				this->erase((*(first++)).first);
		};

		void			swap (map& x) {
			size_type	tmpSize = this->_size;
			key_compare tmpComp = this->_comp;
			allocator_type tmpAlloc = this->_alloc;

			this->_data.swap(x._data);
			this->_size = x._size;
			this->_comp = x._comp;
			this->_alloc = x._alloc;
			x._alloc = tmpAlloc;
			x._comp = tmpComp;
			x._size = tmpSize;
		};

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const { 
			const_iterator itlow = this->lower_bound(k);
			const_iterator itup = this->upper_bound(k);
			return make_pair(itlow, itup);

		};
		pair<iterator,iterator>             equal_range (const key_type& k) {
			iterator itlow = this->lower_bound(k);
			iterator itup = this->upper_bound(k);
			return ft::make_pair(itlow, itup);
		};

	};
}

#endif // __FT_MAP_H__