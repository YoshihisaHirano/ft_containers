#ifndef __FT_VECTOR_H__
#define __FT_VECTOR_H__
#include <memory>
#include "iterator.hpp"
#include <exception>

namespace ft {
	template <typename T>
	class vectorIterator : public iterator_traits<T*>
	{
		private:
		T* ptr;

		public:
		vectorIterator() : ptr(nullptr) {};
		vectorIterator(typename iterator_traits<T*>::pointer pointer) : ptr(pointer) {};
		vectorIterator(const vectorIterator& other) : ptr(other.ptr) {};
		~vectorIterator() { this->ptr = nullptr; };

		vectorIterator &operator=(const vectorIterator& other) { 
			ptr = other.ptr;
			return *this; 
		};

		typename iterator_traits<T*>::reference operator*() { return *(this->ptr);}
		const typename iterator_traits<T*>::reference operator*() const { return *(this->ptr); }

		typename iterator_traits<T*>::pointer operator->() { return this->ptr; }
		const typename iterator_traits<T*>::pointer operator->() const { return this->ptr; }

		typename iterator_traits<T*>::reference operator[](int index) { return *(this->ptr + index); }
		const typename iterator_traits<T*>::reference operator[](int index) const { return *(this->ptr + index); }

		vectorIterator<T> operator++(int) { 
			vectorIterator<T> temp(*this);
			++(this->ptr);
			return temp;
		}
		vectorIterator<T> &operator++() { 
			++(this->ptr);
			return (*this);
		}
		vectorIterator<T> operator--(int) { 
			vectorIterator<T> temp(*this);
			--(this->ptr);
			return temp;
		}
		vectorIterator<T> &operator--() { 
			--(this->ptr);
			return (*this);
		}

		vectorIterator<T> &operator+=(int val) {
			this->ptr += val;
			return (*this);
		}

		vectorIterator<T> &operator-=(int val) {
			this->ptr -= val;
			return (*this);
		}

		vectorIterator<T> &operator+(int val) {
			return vectorIterator<T>(this->ptr += val);
		}

		vectorIterator<T> &operator-(int val) {
			return vectorIterator<T>(this->ptr -= val);
		}

		typename iterator_traits<T*>::difference_type operator-(const vectorIterator<T>& other) {
			return (this->ptr - other.ptr);
		}

		bool operator==(const vectorIterator<T>& other) const { return this->ptr == other.ptr; }
		bool operator!=(const vectorIterator<T>& other) const { return this->ptr != other.ptr; }
		bool operator>=(const vectorIterator<T>& other) const { return this->ptr >= other.ptr; }
		bool operator<=(const vectorIterator<T>& other) const { return this->ptr <= other.ptr; }
		bool operator>(const vectorIterator<T>& other) const { return this->ptr > other.ptr; }
		bool operator<(const vectorIterator<T>& other) const { return this->ptr < other.ptr; }

	};

	template< typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T					value_type;
		typedef	Allocator			allocator_type;
		typedef	T &					reference;
		typedef	T const &			const_reference;
		typedef	T*					pointer;
		typedef T const *			const_pointer;
		typedef	vectorIterator<T>	iterator;
		typedef	unsigned long		size_type;
		typedef	ptrdiff_t			difference_type;

	private:
		size_type			_size;
		size_type			_capacity;
		pointer				_data;
		allocator_type		_alloc;

		void		_removeData(iterator begin, iterator end) {
			for (iterator it = begin; it != end; ++it) 
				this->_alloc.destroy(&(*it));
		};

		void		_fillData(iterator begin, iterator end, value_type val) {
			for (iterator it = begin; it != end; ++it) {
				this->_alloc.destroy(&(*it));
				this->_alloc.construct(&(*it), val);
			}
		};

		size_type	_newCapacity(size_type currSize) { return (static_cast<int>(currSize * 1.5)); };

		void		_reAlloc(size_type newCapacity) { 
			pointer tempAllloc = this->_alloc.allocate(newCapacity);
			std::copy(this->begin(), this->end(), iterator(tempAllloc));
			this->_removeData(this->begin(), this->end());
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = tempAllloc;
			this->_capacity = newCapacity;
		};

	public:
		vector(const allocator_type& alloc = allocator_type()) 
		: _size(0), _capacity(0), _data(nullptr), _alloc(alloc) {};

		// template <class InputIterator> // TODO: enable_if so that sfinae works correctly, otherwise it overshadows fill constructor
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		// : _alloc(alloc) {
		// 	difference_type	sizeWannabe = std::distance(first, last);
		// 	if (sizeWannabe < 0) { 
		// 		throw std::range_error("Error: Wrong iterators range!"); 
		// 	}
		// 	size_type newSize = static_cast<size_type>(sizeWannabe);
		// 	size_type newCapacity = this->_newCapacity(newSize);
		// 	this->_data = this->_alloc.allocate(newCapacity);
		// 	std::copy(first, last, this->begin());
		// };

		vector(size_type vectorSize, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _size(vectorSize), _alloc(alloc) { 
			this->_capacity = this->_newCapacity(vectorSize);
			this->_data = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < vectorSize; i++)
				this->_alloc.construct(this->_data + i, val);
		};

		vector(const vector& other) 
		: _size(other._size), _capacity(other._capacity), _alloc(allocator_type(other._alloc)) {
			this->_data = this->_alloc.allocate(other._capacity);
			std::copy(other.cbegin(), other.cend(), this->begin());
		};

		~vector() {
			this->clear();
		};

		const iterator 	cbegin() const { return iterator(this->_data); };
		const iterator 	cend() const { return iterator(this->_data + this->_size); };
		iterator 		begin() { return iterator(this->_data); };
		iterator 		end() { return iterator(this->_data + this->_size); };
		
		void			clear() {
			this->_removeData(this->begin(), this->end());
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = nullptr;
			this->_size = 0;
			this->_capacity = 0;
		};

		bool			empty() const { return (this->_size == 0); };
		size_type		capacity() const { return (this->_capacity); };
		size_type		size() const { return (this->_size); };
		pointer			data() { return (this->_data); };
		const_pointer	data() const { return (this->_data); };
		allocator_type	get_allocator() { return allocator_type(); };

		void			resize (size_type n, value_type val = value_type()) {
			pointer	tmp;
			size_t	i;
			size_t	new_capacity;

			if (n == this->_size)
				return;
			else if (n < this->_size) {
				for (iterator it = (this->begin() + n); it != this->end(); ++it)
					this->_alloc.destroy(&(*it));
					//TODO check if capacity changes!
			} else {
				new_capacity = this->_newCapacity(n); 
				if (n > this->_capacity) // some shit is happening here
					tmp = this->_alloc.allocate(new_capacity);
				for (i = 0 ; i < this->_size; i++)
					this->_alloc.construct((tmp + i), *(this->_data + i));
				this->clear();
				this->_capacity = new_capacity;
				this->_data = tmp;
				for (i = n - this->_size; i < n ; i++)
					this->_alloc.construct((this->_data + i), val);
			}
			this->_size = n;
		};

		reference		at (size_type n) { 
			if (n >= this->_size)
				throw std::out_of_range("Error: Out of range!");
			return *(this->_data + n);
		};

		const_reference	at (size_type n) const { 
			if (n >= this->_size)
				throw std::out_of_range("Error: Out of range!");
			return *(this->_data + n);
		};

		reference		back () { 
			if (this->_size == 0)
				throw std::out_of_range("Error: Out of range!");
			return *(this->_data + this->_size - 1);
		};

		const_reference	back () const { 
			if (this->_size == 0)
				throw std::out_of_range("Error: Out of range!");
			return *(this->_data + this->_size - 1);
		};

		reference		front () { 
			if (this->_size == 0)
				throw std::out_of_range("Error: Out of range!");
			return *(this->_data);
		};

		const_reference	front () const { 
			if (this->_size == 0)
				throw std::out_of_range("Error: Out of range!");
			return *(this->_data);
		};

		void			push_back (const value_type& val) {
			if (this->_size < this->_capacity) 
				this->_data[this->_size] = val;

			else {
				this->_reAlloc(this->_newCapacity(this->_size + 1));
				this->_data[this->_size] = val;
			}
			this->_size++;
		};

		void			pop_back() {
			if (!this->empty()) {
				this->_alloc.destroy(this->_data + this->_size - 1);
				this->_size--;
				return;
			}
			throw std::underflow_error("Error! The vector is empty!");
		};

		void			reserve (size_type n) {
			// TODO: check that n is not bigger than max_size
			if (n > this->_capacity)
				this->_reAlloc(n);
		};

		iterator		erase (iterator first, iterator last) {
			this->_size -= std::distance(first, last);
			if (last == this->end()) {
				this->_removeData(firts, last);
				return this->end();
			} else {
				this->_removeData(firts, last);
				std::copy(last, this->end(), first);
				return first;
			}
		};

		iterator		erase (iterator position) {
			return this->erase(position, position + 1);
		};

		template <typename InputIterator>
		void			assign (InputIterator first, InputIterator last) {
			if (last - first <= 0)
				throw std::out_of_range("Error: Wrong iterators range!");
		};

		// void			assign (size_type n, const value_type& val) {

		// };
	};
	
}

#endif // __VECTOR_H__