#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <iterator>

namespace ft {
	template<bool is_integral, typename T>
	struct integral_res
	{
		static const bool value = is_integral;
		operator T() const { return value; }
	};

	template <typename T>
	struct integral_type : public integral_res<false, T> {};

	template<> struct integral_type<char>					: public integral_res<true, char> {};
	template<> struct integral_type<char16_t>				: public integral_res<true, char16_t> {};
	template<> struct integral_type<int>					: public integral_res<true, int> {};
	template<> struct integral_type<bool>					: public integral_res<true, bool> {};
	template<> struct integral_type<char32_t>				: public integral_res<true, char32_t> {};
	template<> struct integral_type<wchar_t>				: public integral_res<true, wchar_t> {};
	template<> struct integral_type<signed char>			: public integral_res<true, signed char> {};
	template<> struct integral_type<short int>				: public integral_res<true, short int> {};
	template<> struct integral_type<long int>				: public integral_res<true, long int> {};
	template<> struct integral_type<long long int>			: public integral_res<true, long long int> {};
	template<> struct integral_type<unsigned char>			: public integral_res<true, unsigned char> {};
	template<> struct integral_type<unsigned short int>		: public integral_res<true, unsigned short int> {};
	template<> struct integral_type<unsigned int>			: public integral_res<true, unsigned int> {};
	template<> struct integral_type<unsigned long int>		: public integral_res<true, unsigned long int> {};
	template<> struct integral_type<unsigned long long int>	: public integral_res<true, unsigned long long int> {};


	template<typename T>
	struct is_integral : public integral_type<T> {
	};

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
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	};

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2, Compare comp) {
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
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

	template <bool B, class T = void, class U = void>
	struct conditional {};

	template <class T, class U>
	struct conditional<true, T, U> { typedef T type; };

	template <class T, class U>
	struct conditional<false, T, U> { typedef U type; };
}

#endif // __UTILITY_H__