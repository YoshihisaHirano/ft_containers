#ifndef __ENABLE_IF_H__
#define __ENABLE_IF_H__

namespace ft {
	template <bool Cond, typename T>
	struct enable_if {};
	
	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

#endif // __ENABLE_IF_H__