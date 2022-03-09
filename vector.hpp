#ifndef __FT_VECTOR_H__
#define __FT_VECTOR_H__
#include <memory>
#include "iterator.hpp"
#include <exception>

namespace ft {
	template <typename T>
	class vectorIterator : iterator_traits<T*> 
	{
		private:
		T* ptr;

		public:
		vectorIterator() : ptr(nullptr) {};
		vectorIterator(iterator_traits::pointer pointer) : ptr(pointer) {};
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

		vectorIterator &operator++(int) { 
			vectorIterator temp(*this);
			++(this->ptr);
			return temp;
		}
		vectorIterator &operator++() { 
			++(this->ptr);
			return (*this);
		}
		vectorIterator &operator--(int) { 
			vectorIterator temp(*this);
			--(this->ptr);
			return temp;
		}
		vectorIterator &operator--() { 
			--(this->ptr);
			return (*this);
		}

		vectorIterator &operator+=(int val) {
			this->ptr += val;
			return (*this);
		}

		vectorIterator &operator-=(int val) {
			this->ptr -= val;
			return (*this);
		}

		vectorIterator &operator+(int val) {
			return vectorIterator(this->ptr += val);
		}

		vectorIterator &operator-(int val) {
			return vectorIterator(this->ptr -= val);
		}

		iterator_traits::difference_type operator-(const vectorIterator& other) {
			return (this->ptr - other.ptr);
		}

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
		typedef	T &			reference;
		typedef	T const &	const_reference;
		typedef	T*			pointer;
		typedef T const *	const_pointer;

	private:
		size_t	size;
		size_t	capacity;
		pointer	dataPtr;

	public:
		vector() : size(0), capacity(0), pointer(nullptr) {};
		vector(size_t vectorSize, const value_type& val = value_type()) : size(vectorSize), capacity(vectorSize) { 
			this->dataPtr = Allocator.allocate(vectorSize);
			for (size_t i = 0; i < vectorSize; i++)
				*(this->dataPtr + i) = val;
			// TODO: maybe change capacity to a bigger value (1 += 1/3 or smth), therefore allocate more memory ?
		};
		vector(const vector& other) : size(other.size), capacity(other.capacity) {
			this->dataPtr = Allocator.allocate(other.size);
			for (size_t i = 0; i < other.size; i++)
				*(this->dataPtr + i) = *(other.dataPtr + i);
		};
		~vector() {
			Allocator.deallocate(this->dataPtr, this->capacity);
		};

		const vectorIterator cbegin() const { return vectorIterator(dataPtr); };
		const vectorIterator cend() const { return vectorIterator(dataPtr + size); };
		vectorIterator begin() { return vectorIterator(dataPtr); };
		vectorIterator end() { return vectorIterator(dataPtr + size); };
		
		void	clear() { 
			Allocator.deallocate(this->dataPtr, this->capacity);
			this->dataPtr = nullptr;
			this->size = 0;
			this->capacity = 0;
		};

		bool	empty() const { return (this->size == 0); };
		size_t	capacity() const { return (this->capacity); };
		size_t	size() const { return (this->size); };
		allocator_type	get_allocator() { return allocator_type(); };
		reference at (size_t n) { 
			if (n >= this->size)
				throw std::out_of_range("Error: Out of range!");
			return *(this->dataPtr + n);
		};
		const_reference at (size_type n) const { 
			if (n >= this->size)
				throw std::out_of_range("Error: Out of range!");
			return *(this->dataPtr + n);
		};
	};
	
}

#endif // __VECTOR_H__