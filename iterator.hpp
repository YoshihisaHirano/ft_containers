#ifndef __FT_ITERATOR_H__
#define __FT_ITERATOR_H__
#include <iterator>

namespace ft {
	template <class Iter>
	class iterator_traits {
		public:
		typedef class Iter::value_type			value_type;
		typedef class Iter::difference_type		difference_type;
		typedef class Iter::pointer				pointer;
		typedef class Iter::reference			reference;
		typedef class Iter::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*> {
		public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template <class Iterator>
	class reverse_iterator {
		public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		private:
		iterator_type _base;

		public:
		reverse_iterator() : _base() {};
		reverse_iterator (iterator_type it) : _base(it) {};
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {};

		iterator_type		base() const { return this->_base; };
		reference			operator*() const { return *(--this->_base); };
		reverse_iterator	operator+(difference_type n) const { return reverse_iterator(this->_base - n); };
		reverse_iterator	operator-(difference_type n) const { return reverse_iterator(this->_base + n); };

		reverse_iterator	&operator+=(difference_type n) const {
			this->_base -= n;
			return *this; 
		};

		reverse_iterator	&operator-=(difference_type n) const { 
			this->_base += n;
			return *this;
		};

		reverse_iterator	&operator--() { 
			++(this->_base);
			return *this;
		};

		reverse_iterator	operator--(int) { 
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		};

		reverse_iterator	&operator++() { 
			--(this->_base);
			return *this;
		};
		
		reverse_iterator	operator++(int) { 
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		};

		pointer				operator->() const {
			return &(this->operator*());
		};

		reference			operator[](difference_type n) const { 
			return (this->_base)[n - 1];
		};
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, 
		const reverse_iterator<Iterator>& rev_it) { 
			return reverse_iterator<Iterator>(rev_it + n);
	};

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) {
			return (rhs.base() - lhs.base());
	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() == lhs.base());
	};

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return !(lhs == rhs);
	};

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() < rhs.base());
	};

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() > rhs.base());
	};

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return !(lhs > rhs);
	};

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return !(lhs < rhs);
	};
}

#endif // __ITERATOR_H__