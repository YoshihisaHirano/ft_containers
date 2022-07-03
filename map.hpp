#ifndef __FT_MAP_H__
#define __FT_MAP_H__
#include <memory>
#include <functional>
#include "utility.hpp"
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
		typedef	unsigned long										size_type;
		typedef	ptrdiff_t											difference_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
		public:
			Compare comp;

			value_compare(void) : comp(Compare()) {}
			value_compare (Compare c) : comp(c) {}
		
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

		public:
		typedef typename bs_tree<value_type, value_compare, Alloc>::iterator				iterator;
		typedef typename bs_tree<value_type, value_compare, Alloc>::const_iterator		const_iterator;
		typedef reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef reverse_iterator<iterator>							reverse_iterator;

		private:
		bs_tree<value_type, value_compare, Alloc>	_data;
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
			iterator it_find = this->find(k);
			if (it_find != this->end()) { return (*it_find).second; }
			ft::pair<key_type, mapped_type> newPair(k, mapped_type());
			iterator it_ins = this->_data.insert(newPair);
			this->_size++;
			return (*it_ins).second;
		};

		iterator		begin() { return this->_data.begin(); };
		const_iterator	begin() const { return this->_data.cbegin(); };
		reverse_iterator rbegin() { return reverse_iterator(this->end()); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_data.cend()); };
		reverse_iterator rend() { return reverse_iterator(this->begin()); };
		const_reverse_iterator rend() const { return const_reverse_iterator(this->_data.cbegin()); };;
		iterator		end() { return this->_data.end(); };
		const_iterator	end() const { return this->_data.cend(); };
		bool			empty() const { return this->_size == 0; };
		allocator_type	get_allocator() const { return allocator_type(); };
		key_compare		key_comp() const { return key_compare(); };
		value_compare	value_comp() const { return value_compare(key_compare()); };
		size_type		max_size() const { return this->_data.max_size(); };
		size_type		size() const { return this->_size; };


		mapped_type& at (const key_type& k) {
			return (*this)[k];
		};

		const mapped_type& at (const key_type& k) const {
			return (*this)[k];
		};

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

		pair<iterator,bool> insert(const value_type& val) {
			iterator it = this->find(val.first);
			if (it == this->end()) {
				it = this->_data.insert(val);
				this->_size++;
				return pair<iterator,bool>(it, true);
			}
			return pair<iterator,bool>(it, false);
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
			bst_node<value_type>	*tmp = this->_data.getRoot();
			bst_node<value_type>	*tmp2 = NULL;

			while(tmp) {
				tmp2 = tmp;
				if (tmp->value.first == k)
					return iterator(tmp, this->_data.getRoot());
				if (this->_comp(k, tmp->value.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (!tmp2)
				return this->end();
			if (this->_comp(tmp2->value.first, k))
				return iterator(tmp2->successor(), this->_data.getRoot());
			return iterator(tmp2, this->_data.getRoot());
		};

		const_iterator	lower_bound (const key_type& k) const { 
			return const_iterator(this->lower_bound(k));
		};

		iterator		upper_bound (const key_type& k) {
			bst_node<value_type>	*tmp = this->_data.getRoot();
			bst_node<value_type>	*tmp2 = NULL;

			while(tmp) {
				tmp2 = tmp;
				if (tmp->value.first == k)
					return iterator(tmp->successor(), this->_data.getRoot());
				if (this->_comp(k, tmp->value.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (!tmp2)
				return this->end();
			if (this->_comp(tmp2->value.first, k))
				return iterator(tmp2->successor(), this->_data.root);
			return iterator(tmp2, this->_data.getRoot());
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

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size()) { return false; }
		typename map<Key,T,Compare,Alloc>::const_iterator itl = lhs.begin();
		typename map<Key,T,Compare,Alloc>::const_iterator itr = rhs.begin();
		for (; itl != lhs.end(); ++itl, ++itr) {
			if (*itl != *itr) { return false; }
		}
		return true;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return !(lhs == rhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return (lhs < rhs || lhs == rhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return !(lhs <= rhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return (lhs > rhs || lhs == rhs);
	};
}

namespace std {
	template <class Key, class T, class Compare, class Alloc>
	void	swap (ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y) {
		x.swap(y);
	};
}

#endif // __FT_MAP_H__