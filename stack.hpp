#ifndef __FT_STACK_H__
#define __FT_STACK_H__
#include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack {
		public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		protected:
		container_type	c;

		public:
		explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {};

		bool				empty() const { return c.empty(); };
		size_type			size() const { return c.size(); };
		value_type			&top() { return c.back(); };
		const value_type	&top() const { return c.back(); };
		void				push(const value_type& val) { return c.push_back(val); };
		void				pop() { return c.pop_back(); };

		template <T, Container>
		friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		template <T, Container>
		friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		template <T, Container>
		friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		template <T, Container>
		friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		template <T, Container>
		friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs);

		template <T, Container>
		friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	};

	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c == rhs.c);
	};

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs == rhs);
	};

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c < rhs.c);
	};

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(rhs < lhs);
	};

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (rhs < lhs);
	};

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs < rhs);
	};
}

#endif // __STACK_H_