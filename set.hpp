#ifndef _FT_SET_H__
#define _FT_SET_H__
#include <memory>
#include <functional>
#include "bst.hpp"
#include "utility.hpp"
#include "iterator.hpp"

namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
		public:
		typedef const T											value_type;
		typedef const T											key_type;
		typedef Compare											key_compare;
		typedef Compare											value_compare;
		typedef Alloc											allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef	typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename bs_tree<value_type, Compare, Alloc>::iterator	iterator;
		typedef typename bs_tree<value_type, Compare, Alloc>::iterator	const_iterator;
		typedef reverse_iterator<iterator>						const_reverse_iterator;
		typedef reverse_iterator<iterator>						reverse_iterator;
		typedef	unsigned long									size_type;
		typedef	ptrdiff_t										difference_type;

		private:
		bs_tree<value_type, Compare, Alloc>	_data;
		size_type			_size;
		key_compare			_comp;
		allocator_type		_alloc;

		public:
		set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
		: _data(NULL, value_compare(comp)), _size(0), _comp(comp), _alloc(alloc) {};

		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		: _data(NULL, value_compare(comp)), _size(0), _comp(comp), _alloc(alloc) {
			this->insert(first, last);
		};

		set(const set& x) : _data(NULL, value_compare(x._comp)), _size(0), _comp(x._comp), _alloc(x._alloc) {
			this->insert(x.begin(), x.end());
		};
		~set() {
			this->clear();
		};

		set& operator=(const set& x) {
			this->_data = x._data;
			this->_size = x._size;
			this->_comp = x._comp;
			return *this;
		};

		iterator		begin() { return this->_data.begin(); };
		const_iterator	begin() const { return this->_data.begin(); };
		reverse_iterator rbegin() { return reverse_iterator(this->end()); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_data.end()); };
		reverse_iterator rend() { return reverse_iterator(this->begin()); };
		const_reverse_iterator rend() const { return const_reverse_iterator(this->_data.begin()); };;
		iterator		end() { return this->_data.end(); };
		const_iterator	end() const { return this->_data.end(); };
		bool			empty() const { return this->_size == 0; };
		allocator_type	get_allocator() const { return allocator_type(); };
		size_type		max_size() const { return this->_data.max_size(); };
		size_type		size() const { return this->_size; };
		key_compare		key_comp() const { return key_compare(); };
		value_compare	value_comp() const { return value_compare(); };

		void			clear() {
			this->_size = 0;
			this->_data.clear();
		};

		iterator		lower_bound (const value_type& val) const {
			bst_node<value_type>	*tmp = this->_data.root;
			bst_node<value_type>	*tmp2 = NULL;

			while(tmp) {
				tmp2 = tmp;
				if (tmp->value == val)
					return iterator(tmp, this->_data.root);
				if (this->_comp(val, tmp->value))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (!tmp2)
				return this->end();
			if (this->_comp(tmp2->value, val))
				return iterator(tmp2->successor(), this->_data.root);
			return iterator(tmp2, this->_data.root);
		};

		iterator		upper_bound (const value_type& val) const {
			bst_node<value_type>	*tmp = this->_data.root;
			bst_node<value_type>	*tmp2 = NULL;

			while(tmp) {
				tmp2 = tmp;
				if (tmp->value == val)
					return iterator(tmp->successor(), this->_data.root);
				if (this->_comp(val, tmp->value))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (!tmp2)
				return this->end();
			if (this->_comp(tmp2->value, val))
				return iterator(tmp2->successor(), this->_data.root);
			return iterator(tmp2, this->_data.root);
		};

		void			erase (iterator position) {
			this->_data.remove(*position);
			this->_size--;
		};

		size_type		erase (const value_type& val) {
			iterator it = this->find(val);
			if (it == this->end())
				return 0;
			this->_data.remove(*it);
			this->_size--;
			return 1;
		};

		void			erase (iterator first, iterator last) {
			while (first != last)
				this->erase((*(first++)));
		};

		iterator		find(const value_type& val) const {
			iterator it = this->_data.find(val);
			return it;
		};

		size_type		count(const value_type& val) const {
			return (this->find(val) == this->_data.end()) ? 0 : 1;
		};

		pair<iterator,bool> insert(const value_type& val) {
			iterator it = this->find(val);
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

		pair<iterator,iterator>             equal_range (const value_type& val) const {
			iterator itlow = this->lower_bound(val);
			iterator itup = this->upper_bound(val);
			return ft::make_pair(itlow, itup);
		};

		void			swap (set& x) {
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
	};

	template <class T, class Compare, class Alloc>
	void	swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y) {
		x.swap(y);
	};

	template <class T, class Compare, class Alloc>
	bool operator==(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size()) { return false; }
		typename set<T,Compare,Alloc>::const_iterator itl = lhs.begin();
		typename set<T,Compare,Alloc>::const_iterator itr = rhs.begin();
		for (; itl != lhs.end(); ++itl, ++itr) {
			if (*itl != *itr) { return false; }
		}
		return true;
	};

	template <class T, class Compare, class Alloc>
	bool operator!=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return !(lhs == rhs);
	};

	template <class T, class Compare, class Alloc>
	bool operator<(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class T, class Compare, class Alloc>
	bool operator<=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return !(lhs > rhs);
	};

	template <class T, class Compare, class Alloc>
	bool operator>(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return (rhs < lhs);
	};

	template <class T, class Compare, class Alloc>
	bool operator>=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return !(lhs < rhs);
	};
}

#endif // __SET_H__