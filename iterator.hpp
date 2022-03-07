#ifndef __FT_ITERATOR_H__
#define __FT_ITERATOR_H__
#include <iterator>

namespace ft {
	template <typename Iter>
	struct iterator_traits {
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*> {
		typedef typename T	value_type;
		typedef ptrdiff_t	difference_type;
		typedef typename T*	pointer;
		typedef typename T&	reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	};
}

#endif // __ITERATOR_H__