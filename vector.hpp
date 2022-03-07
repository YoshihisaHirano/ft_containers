#ifndef __FT_VECTOR_H__
#define __FT_VECTOR_H__
#include <memory>
#include "iterator.hpp"

namespace ft {
	template <typename T>
	class vectorIterator : iterator_traits<T*> 
	{
		private:
		T* ptr;

		public:
		vectorIterator() : ptr(nullptr) {};
		vectorIterator(const vectorIterator& other) : ptr(other.ptr);
		~vectorIterator();

		vectorIterator &operator=(const vectorIterator& other) { 
			ptr = other.ptr;
			return *this; 
		};
		iterator_traits::reference operator*() { return *(this->ptr);}
		const iterator_traits::reference operator*() const { return *(this->ptr); }

		iterator_traits::pointer operator->() { return this->ptr; }
		const iterator_traits::pointer operator->() const { return this->ptr; }

		iterator_traits::reference operator[](int index) { return *(this->ptr + index); }
		const iterator_traits::reference operator[](int index) const { return *(this->ptr + index); }

		bool operator==(const vectorIterator& other) const { return this->ptr == other.ptr; }
		bool operator!=(const vectorIterator& other) const { return this->ptr != other.ptr; }
		bool operator>=(const vectorIterator& other) const { return this->ptr >= other.ptr; }
		bool operator<=(const vectorIterator& other) const { return this->ptr <= other.ptr; }
		bool operator>(const vectorIterator& other) const { return this->ptr > other.ptr; }
		bool operator<(const vectorIterator& other) const { return this->ptr < other.ptr; }


	};

	template< typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T			value_type;
		typedef	Allocator	allocator_type;
		typedef	T&			reference;
		typedef	T const &	const_reference;
		typedef	T*			pointer;
		typedef T const *	const_pointer;
	private:
		size_t	size;
		size_t	capacity;
		pointer	dataPtr;

	public:
		vector() : size(0), capacity(0), pointer(nullptr) {};
		~vector();
	};
	
}

#endif // __VECTOR_H__