#ifndef __FT_VECTOR_H__
#define __FT_VECTOR_H__
#include <memory>
#include <exception>
#include <iterator>
#include <iostream>
#include "utility.hpp"

namespace ft {
	template <typename T>
	class vectorIterator : public iterator_traits<T*>
	{
		private:
		T* ptr;

		public:
		typedef T*												iterator_type;
		typedef typename iterator_traits<T*>::pointer			pointer;
		typedef typename iterator_traits<T*>::reference			reference;
		typedef typename iterator_traits<T*>::difference_type	difference_type;

		vectorIterator() : ptr(NULL) {};
		vectorIterator(pointer pointer) : ptr(pointer) {};
		vectorIterator(const vectorIterator& other) : ptr(other.ptr) {};
		~vectorIterator() { this->ptr = NULL; };

		vectorIterator &operator=(const vectorIterator& other) { 
			ptr = other.ptr;
			return *this; 
		};

		reference operator*() { return *(this->ptr);}
		const reference operator*() const { return *(this->ptr); }

		pointer operator->() { return this->ptr; }
		const pointer operator->() const { return this->ptr; }

		reference operator[](int index) { return *(this->ptr + index); }
		const reference operator[](int index) const { return *(this->ptr + index); }

		vectorIterator operator++(int) { 
			vectorIterator temp(*this);
			++(this->ptr);
			return temp;
		}
		vectorIterator &operator++() { 
			++(this->ptr);
			return (*this);
		}
		vectorIterator operator--(int) { 
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

		vectorIterator operator+(difference_type val) const {
			vectorIterator  tmp(*this);
			return vectorIterator(tmp += val);
		}

		vectorIterator operator-(difference_type val) const {
			vectorIterator  tmp(*this);
			return vectorIterator(tmp -= val);
		}

		difference_type operator-(const vectorIterator& other) {
			return (this->ptr - other.ptr);
		}

		operator vectorIterator<const T>() const {
			return vectorIterator<const T>(this->ptr);
		}

		pointer	getPointer() const { return this->ptr; }
	};

	template <typename T1, typename T2>
	bool operator==(const vectorIterator<T1>& lhs, const vectorIterator<T2>&
	        rhs) {
		return (rhs.getPointer() == lhs.getPointer());
	};

	template <typename T1, typename T2>
	bool operator!=(const vectorIterator<T1>& lhs, const vectorIterator<T2>&
	rhs) {
		return !(rhs == lhs);
	};

	template <typename T1, typename T2>
	bool operator<(const vectorIterator<T1>& lhs, const vectorIterator<T2>&
	rhs) {
		return (lhs.getPointer() < rhs.getPointer());
	};

	template <typename T1, typename T2>
	bool operator>(const vectorIterator<T1>& lhs, const vectorIterator<T2>&
	rhs) {
		return (rhs < lhs);
	};

	template <typename T1, typename T2>
	bool operator>=(const vectorIterator<T1>& lhs, const vectorIterator<T2>&
	rhs) {
		return !(lhs < rhs);
	};

	template <typename T1, typename T2>
	bool operator<=(const vectorIterator<T1>& lhs, const vectorIterator<T2>&
	rhs) {
		return !(lhs > rhs);
	};

	template< typename T, typename Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T											value_type;
		typedef	Allocator									allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef	vectorIterator<T>							iterator;
		typedef vectorIterator<const T>						const_iterator;
		typedef reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;
		typedef	unsigned long								size_type;
		typedef	ptrdiff_t									difference_type;

	private:
		size_type			_size;
		size_type			_capacity;
		pointer				_data;
		allocator_type		_alloc;

		void		_removeData(iterator begin, iterator end) {
			for (iterator it = begin; it != end; ++it) 
				this->_alloc.destroy(it.getPointer());
		};

		void		_fillData(iterator begin, iterator end, value_type val) {
			for (iterator it = begin; it != end; ++it)
				this->_alloc.construct(it.getPointer(), val);
		};

		size_type	_newCapacity(size_type currSize) {
			if (this->_size == 0) return currSize;
			return (static_cast<int>(currSize * 2));
		};

		void		_reassignVector(pointer newData, size_type newCapacity, size_type newSize)
		{
			this->_data = newData;
			this->_capacity = newCapacity;
			this->_size = newSize;
		}

		void		_reAlloc(size_type newCapacity) {
			pointer tempAllloc = this->_alloc.allocate(newCapacity);
			if (this->_size > 0)
				std::copy(this->begin(), this->end(), iterator(tempAllloc));
			this->_removeData(this->begin(), this->end());
			if (this->_data) {
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = NULL;
			}
			this->_reassignVector(tempAllloc, newCapacity, this->_size);
		};

		void		_checkRangeOverflow(size_type n) const {
			if (n >= this->_size)
				throw std::out_of_range("Error: Out of range!");
		};

		void		_throwIfEmpty() { 
			if (this->empty())
				throw std::underflow_error("Error: Trying to access objects inside an empty vector!");
		};

		void		_fullClear() { 
			this->_removeData(this->begin(), this->end());
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_reassignVector(NULL, 0, 0);
		}

		template<class Iterator>
		bool	_validate_insert_size(Iterator first, Iterator last, size_t range) {
			pointer tmp_buf = this->_alloc.allocate(range);
			bool res = true;
			size_t i = 0;
			for (;first != last; ++first, ++i) {
				try { tmp_buf[i] = *first; }
				catch (...) { res = false; break; }
			}
			_alloc.deallocate(tmp_buf, range);
			return res;
		}

	public:
		vector(const allocator_type& alloc = allocator_type()) 
		: _size(0), _capacity(0), _data(NULL), _alloc(alloc) {};

		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		: _alloc(alloc) {
			difference_type	sizeWannabe = std::distance(first, last);
			std::cout << "dst: " << sizeWannabe << std::endl;
			if (sizeWannabe < 0) { 
				throw std::range_error("Error: Wrong iterators range!"); 
			}
			size_type newSize = static_cast<size_type>(sizeWannabe);
			this->_data = this->_alloc.allocate(newSize);
			this->_reassignVector(this->_data, newSize, newSize);
			std::copy(first, last, this->begin());
		};

		vector(size_type vectorSize, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _size(vectorSize), _capacity(vectorSize), _alloc(alloc) { 
			this->_data = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < vectorSize; i++)
				this->_alloc.construct(this->_data + i, val);
		};

		vector(const vector& other) 
		: _size(other._size), _capacity(other._capacity), _alloc(allocator_type(other._alloc)) {
			this->_data = this->_alloc.allocate(other._capacity);
			std::copy(other.begin(), other.end(), this->begin());
		};

		~vector() {
			this->_fullClear();
		};

		vector			&operator=(const vector& other) {
			this->_fullClear();
			this->_alloc = other.get_allocator();
			this->assign(other.begin(), other.end());
			this->_size = other.size();
			this->_capacity = other.capacity();
			return *this;
		};

		reference operator[](size_type const &n) {
			return (this->_data)[n];
		};

		const_reference operator[](size_type const &n) const { 
			return (this->_data)[n];
		};

		iterator		begin() { return iterator(this->_data); };
		const_iterator	begin() const { return const_iterator(this->_data); };
		iterator		end() { return iterator(this->_data + this->_size); };
		const_iterator	end() const { return const_iterator(this->_data + this->_size); };
		reverse_iterator	rbegin() { return reverse_iterator(this->end()); };
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->end()); };
		reverse_iterator	rend() { return reverse_iterator(this->begin()); };
		const_reverse_iterator	rend() const { return const_reverse_iterator(this->begin()); };
		
		void			clear() {
			this->_removeData(this->begin(), this->end());
			this->_size = 0;
		};

		bool			empty() const { return (this->_size == 0); };
		size_type		capacity() const { return this->_capacity; };
		size_type		size() const { return this->_size; };
		pointer			data() { return this->_data; };
		const_pointer	data() const { return this->_data; };
		allocator_type	get_allocator() const { return allocator_type(); };
		size_type		max_size() const {return this->_alloc.max_size(); };

		void			resize (size_type n, value_type val = value_type()) {
			if (n == this->_size)
				return;
			if (n > this->_capacity)
				this->_capacity == 0 ? this->_reAlloc(n) : this->_reAlloc(this->_capacity * 2);
			if (n < this->_size) 
				this->_removeData(this->begin() + n, this->end());
			else 
				this->_fillData(this->begin() + this->_size, this->end() + (n - this->_size), val);
			this->_size = n;
		};

		reference		at (size_type n) { 
			this->_checkRangeOverflow(n);
			return *(this->_data + n);
		};

		const_reference	at (size_type n) const { 
			this->_checkRangeOverflow(n);
			return *(this->_data + n);
		};

		reference		back () { 
			return *(this->_data + this->_size - 1);
		};

		const_reference	back () const { 
			return *(this->_data + this->_size - 1);
		};

		reference		front () { 
			return *(this->_data);
		};

		const_reference	front () const { 
			return *(this->_data);
		};

		void			push_back (const value_type& val) {
			if (this->_size == this->_capacity) {
				size_type newCapacity = this->_size ? this->_size * 2 : 2;
				this->_reAlloc(newCapacity);
			}
			this->_alloc.construct(this->_data + this->_size, val);
			this->_size++;
		};

		void			pop_back() {
			this->_alloc.destroy(this->_data + this->_size);
			this->_size--;
		};

		void			reserve (size_type n) {
			if (n <= this->_capacity) { return; }
			this->_reAlloc(n);
		};

		iterator		erase (iterator first, iterator last) {
			if (last == this->end()) {
				this->_removeData(first, last);
				this->_size -= std::distance(first, last);
				return this->end();
			} else {
				this->_removeData(first, last);
				std::copy(last, this->end(), first);
				this->_size -= std::distance(first, last);
				return first;
			}
		};

		iterator		erase (iterator position) {
			this->_alloc.destroy(position.getPointer());
			size_type idx = position - this->begin();
			for (size_type i = idx; i < this->_size; i++)
				this->_data[i] = this->_data[i+1];
			this->_size--;
			return position;
		};

		template <class InputIterator>
		void			assign (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
			difference_type sdst = std::distance(first, last);
			if (sdst < 0)
				throw std::range_error("Error: Wrong iterators range!");
			size_type dst = static_cast<size_type>(sdst);
			if (dst >= this->_capacity) {
				this->_fullClear();
				this->_capacity = dst;
				this->_data = this->_alloc.allocate(dst);
			} else
				this->_removeData(this->begin(), this->end());
			this->_size = dst;
			std::copy(first, last, this->begin());
		};

		void			assign (size_type n, const value_type& val) {
			if (n > this->_capacity) {
				this->_fullClear();
				this->_capacity = n;
				this->_data = this->_alloc.allocate(n);
			} else
				this->_removeData(this->begin(), this->end());
			this->_size = n;
			this->_fillData(this->begin(), this->end(), val);
		};

		void			insert(iterator position, size_type n, const value_type& val) {
			if (n + this->_size > this->_capacity) {
				size_type newSize = this->_size + n;
				size_type newCapacity = newSize;
				if (n == 1 && this->_size == this->_capacity)
					newCapacity = this->_capacity == 0 ? 2 : this->_size * 2;
				pointer temp = this->_alloc.allocate(newCapacity);
				iterator tempIter = iterator(temp);
				std::copy(this->begin(), position, tempIter);
				tempIter += std::distance(this->begin(), position);
				this->_fillData(tempIter, tempIter + n, val);
				std::copy(position, this->end(), tempIter + n);
				this->_fullClear();
				this->_reassignVector(temp, newCapacity, newSize);
			} 
			else {
				iterator oldEnd = this->end();
				this->_size += n;
				std::copy_backward(position, oldEnd, this->end());
				this->_fillData(position, position + n, val);
			}
		};

		iterator		insert(iterator position, const value_type& val) {
			difference_type distanceFromBegin = std::distance(this->begin(), position);
			this->insert(position, 1, val);
			return (this->begin() + distanceFromBegin);
		};

		template <class InputIterator>
		void			insert(iterator position, InputIterator first, InputIterator last, 
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
			difference_type sdst = std::distance(first, last);
			if (sdst < 0)
				throw std::range_error("Error: Wrong iterators range!");
			size_type dst = static_cast<size_type>(sdst);
			if (!this->_validate_insert_size(first, last, dst))
				throw std::exception();
			if (this->_size + dst > this->_capacity) {
				size_type newSize = this->_size + dst;
				size_type newCapacity = this->_size * 2 > newSize ? this->_size * 2 : newSize;
				pointer temp = this->_alloc.allocate(newCapacity);
				iterator tempIter = iterator(temp);
				std::copy(this->begin(), position, tempIter);
				tempIter += std::distance(this->begin(), position);
				std::copy(first, last, tempIter);
				std::copy(position, this->end(), tempIter + dst);
				this->_fullClear();
				this->_reassignVector(temp, newCapacity, newSize);
			} else {
				iterator oldEnd = this->end();
				this->_size += dst;
				std::copy_backward(position, oldEnd, this->end());
				std::copy(first, last, position);
			}
		};

		void			swap(vector& other) {
			pointer tempData = this->_data;
			size_type tempSize = this->_size;
			size_type tempCapacity = this->_capacity;
			allocator_type tempAlloc = this->_alloc;

			this->_size = other._size;
			this->_capacity = other._capacity;
			this->_data = other._data;
			this->_alloc = other._alloc;
			other._size = tempSize;
			other._capacity = tempCapacity;
			other._data = tempData;
			other._alloc = tempAlloc;
		};
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size()) {
			return false;
		}
		typename vector<T,Alloc>::const_iterator it1 = lhs.begin();
		typename vector<T,Alloc>::const_iterator it2 = rhs.begin();
		for (; it1 != lhs.end(); ++it1, ++it2) {
			if (*it1 != *it2) { return false; }
		}
		return true;
	};
	
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	};
	
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename vector<T,Alloc>::const_iterator first1 = lhs.begin();
		typename vector<T,Alloc>::const_iterator first2 = rhs.begin();
		typename vector<T,Alloc>::const_iterator last1 = lhs.end();
		typename vector<T,Alloc>::const_iterator last2 = rhs.end();

		for (; first1 != last1; ++first1, ++first2) { 
			if (first2 == last2 || *first1 > *first2) { return false; }
			else if (*first1 < *first2) { return true; }
		}
		return (*first2 != *last2);
	};

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs < rhs || lhs == rhs);
	};

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	};

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs || lhs == rhs);
	};

}

namespace std {
	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
		x.swap(y);
	};
}

#endif // __VECTOR_H__