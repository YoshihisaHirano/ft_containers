#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <iterator>

namespace ft {
	template <bool is_integral, typename T>
	struct integral_res {
		static const bool value = is_integral;
	};

	template <typename T>
	struct integral_type : public integral_res<false, T> {};

	template <>
	struct integral_type<char> : public integral_res<true, char> {};

	template <>
	struct integral_type<bool> : public integral_res<true, bool> {};

	template <>
	struct integral_type<int> : public integral_res<true, int> {};

	template <>
	struct integral_type<char16_t> : public integral_res<true, char16_t> {};

	template <>
	struct integral_type<char32_t> : public integral_res<true, char32_t> {};

	template <>
	struct integral_type<wchar_t> : public integral_res<true, wchar_t> {};

	template <>
	struct integral_type<signed char> : public integral_res<true, signed char> {};

	template <>
	struct integral_type<short int> : public integral_res<true, short int> {};

	template <>
	struct integral_type<long int> : public integral_res<true, long int> {};

	template <>
	struct integral_type<long long int> : public integral_res<true, long long int> {};

	template <>
	struct integral_type<unsigned char> : public integral_res<true, unsigned char> {};

	template <>
	struct integral_type<unsigned short int> : public integral_res<true, unsigned short int> {};

	template <>
	struct integral_type<unsigned int> : public integral_res<true, unsigned int> {};

	template <>
	struct integral_type<unsigned long int> : public integral_res<true, unsigned long int> {};

	template <>
	struct integral_type<unsigned long long int> : public integral_res<true, unsigned long long int> {};

	template <typename T>
	struct is_integral : public integral_type<T> {};

}

namespace ft {
	template <typename T1, typename T2>
	class pair
	{
	public:
		T1 first;
		T2 second;

		typedef T1 first_type;
		typedef T2 second_type;

		pair() : first(first_type()), second(second_type()) {};
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
		pair (const first_type& a, const second_type& b) : first(a), second(b) {};
		
		pair& operator=(const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		};
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	};

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first < rhs.first || (!(rhs.first > lhs.first) && lhs.second < rhs.second));
	};

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs < rhs);
	};
	
	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y) {
		return pair<T1,T2>(x, y);
	};
}

namespace ft {
	template <bool Cond, typename T = void>
	struct enable_if {};
	
	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

namespace ft {

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2) {
		for (; first1 != last1; first1++, first2++) {
			if (first2 == last2 || *first2 < *first1) { return false; }
			else if (*first1 < *first2) { return true; }
		}
		return (*first2 != *last2);
	};

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2, Compare comp) {
		for (; first1 != last1; first1++, first2++) {
			if (first2 == last2 || comp(*first2, *first1)) { return false; }
			else if (comp(*first1, *first2)) { return true; }
		}
		return (*first2 != *last2);
	};

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		for (; first1 != last1; first1++, first2++) {
			if (*first1 != *first2) { return false; }
		}
		return true;
	};

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred) {
		for (; first1 != last1; first1++, first2++) {
			if (!pred(*first1, *first2)) { return false; }
		}
		return true;
	};
}

// namespace ft {
// 	template <class Iter>
// 	class iterator_traits {
// 		public:
// 		typedef typename Iter::value_type			value_type;
// 		typedef typename Iter::difference_type		difference_type;
// 		typedef typename Iter::pointer				pointer;
// 		typedef typename Iter::reference			reference;
// 		typedef typename Iter::iterator_category	iterator_category;
// 	};

// 	template <class T>
// 	class iterator_traits<T*> {
// 		public:
// 		typedef T								value_type;
// 		typedef ptrdiff_t						difference_type;
// 		typedef T*								pointer;
// 		typedef T&								reference;
// 		typedef std::random_access_iterator_tag	iterator_category;
// 	};

// 	template <class Iterator>
// 	class reverse_iterator {
// 		public:
// 		typedef Iterator												iterator_type;
// 		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
// 		typedef typename iterator_traits<Iterator>::value_type			value_type;
// 		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
// 		typedef typename iterator_traits<Iterator>::pointer				pointer;
// 		typedef typename iterator_traits<Iterator>::reference			reference;

// 		private:
// 		iterator_type _base;

// 		public:
// 		reverse_iterator() : _base() {};
// 		reverse_iterator (iterator_type it) : _base(it) {};
// 		template <class Iter>
// 		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base(rev_it.base()) {};

// 		iterator_type		base() const { return this->_base; };
// 		reference			operator*() const { 
// 			iterator_type tmp = _base;
//             return (*(--tmp));
// 		};
// 		reverse_iterator	operator+(difference_type n) const { return reverse_iterator(this->_base - n); };
// 		reverse_iterator	operator-(difference_type n) const { return reverse_iterator(this->_base + n); };

// 		reverse_iterator	&operator+=(difference_type n) const {
// 			this->_base -= n;
// 			return *this;
// 		};

// 		reverse_iterator	&operator-=(difference_type n) const { 
// 			this->_base += n;
// 			return *this;
// 		};

// 		reverse_iterator	&operator--() { 
// 			++(this->_base);
// 			return *this;
// 		};

// 		reverse_iterator	operator--(int) { 
// 			reverse_iterator temp = *this;
// 			--(*this);
// 			return temp;
// 		};

// 		reverse_iterator	&operator++() { 
// 			--(this->_base);
// 			return *this;
// 		};
		
// 		reverse_iterator	operator++(int) { 
// 			reverse_iterator temp = *this;
// 			++(*this);
// 			return temp;
// 		};

// 		pointer				operator->() const {
// 			return &(this->operator*());
// 		};

// 		reference			operator[](difference_type n) const { 
// 			return (this->_base)[n - 1];
// 		};
// 	};

// 	template <class Iterator>
// 	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, 
// 		const reverse_iterator<Iterator>& rev_it) { 
// 			return reverse_iterator<Iterator>(rev_it + n);
// 	};

// 	template <class Iterator>
// 	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
// 		const reverse_iterator<Iterator>& rhs) {
// 			return (rhs.base() - lhs.base());
// 	};

// 	template <class Iterator>
// 	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
// 		return (rhs.base() == lhs.base());
// 	};

// 	template <class Iterator>
// 	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
// 		return !(lhs == rhs);
// 	};

// 	template <class Iterator>
// 	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
// 		return (lhs.base() < rhs.base());
// 	};

// 	template <class Iterator>
// 	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
// 		return (rhs < lhs);
// 	};

// 	template <class Iterator>
// 	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
// 		return !(lhs > rhs);
// 	};

// 	template <class Iterator>
// 	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
// 		return !(lhs < rhs);
// 	};
//}

#endif // __UTILITY_H__