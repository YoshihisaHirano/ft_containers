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
	class reverse_iterator : public iterator_traits<Iterator> {
		public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;
	};
}

#endif // __ITERATOR_H__