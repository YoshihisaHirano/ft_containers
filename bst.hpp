#ifndef __FT_BST_H__
#define __FT_BST_H__
#include <memory>
#include <exception>
#include <iostream>
#include <iterator>
#include "iterator.hpp"

namespace ft {
	template <typename T>
	struct bst_node
	{
		typedef bst_node* node;

		T			value;
		node		left;
		node		right;
		node		parent;

		bst_node(T value, node lt = NULL, node rt = NULL, node pt = NULL)
		: value(value), left(lt), right(rt), parent(pt) {};
	};

	template <typename T, class Compare = std::less<T> >
	class bs_tree {
		protected:
		typedef bst_node<T>			node;
		typedef bs_tree<T, Compare>	tree;

		template <bool isConst>
		class bst_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
		private:

		node		*position;
		const tree	*tree;

		public:
		typedef typename ft::conditional<isConst, const T&, T&>::type	reference;
		typedef typename ft::conditional<isConst, const T*, T*>::type   pointer;
		

		bst_iterator() : position(NULL), tree(NULL) {};
		bst_iterator(const bst_iterator& other) : position(other.position), tree(other.tree) {};
		bst_iterator(bst_node<T> *pos, const bs_tree<T, Compare> *tr) : position(pos), tree(tr) {};
		~bst_iterator() {};
		template <bool B>
		bst_iterator(const bst_iterator<B> & x, typename ft::enable_if<!B>::type* = 0){
			this->position = x.getPos();
			this->tree = x.getTree();
		};

		bst_iterator	&operator=(const bst_iterator& other) {
			this->position = other.position;
			this->tree = other.tree;
			return *this;
		};

		const bs_tree<T, Compare> *getTree() const { return this->tree; }
		node	*getPos() const { return this->position; }

		reference			operator*() { return this->position->value; };
		pointer				operator->() { return &(this->position->value); };

		bst_iterator		&operator++() {
			if (this->tree->empty()) {
				throw std::underflow_error("Trying to increment over an empty tree");
			}
			if (this->position->right != NULL) {
				this->position = this->position->right;
				while (this->position->left != NULL)
					this->position = this->position->left;
			} else {
				bst_node<T>	*tmp = this->position->parent;
				while (tmp != NULL && this->position == tmp->right) { 
					this->position = tmp;
					tmp = tmp->parent;
				}
				this->position = tmp;
			}
			return *this;
		};

		bst_iterator		operator++(int) {
			bst_iterator temp = *this;
			this->operator++();
			return temp;
		};

		bst_iterator		&operator--() {
			if (this->tree->empty()) {
				throw std::underflow_error("Trying to decrement over an empty tree");
			}
			if (this->position == NULL) {
				this->position = tree->root;
				while (this->position->right != NULL) 
					this->position = this->position->right;
			}
			else if (this->position->left != NULL) {
				this->position = this->position->left;
				while (this->position->right != NULL) 
					this->position = this->position->right;
			}
			else {
				bst_node<T>	*tmp = this->position->parent;
				while (tmp != NULL && this->position == tmp->left) { 
					this->position = tmp;
					tmp = tmp->parent;
				}
				this->position = tmp;
			}
			return *this;
		};

		bst_iterator		operator--(int) {
			bst_iterator temp = *this;
			this->operator--();
			return temp;
		};

		bool operator==(const bst_iterator& rhs) const {
			return (rhs.position == this->position && rhs.tree == this->tree);
		};

		bool operator!=(const bst_iterator& rhs) const {
			return !(rhs.operator==(*this));
		};
	};
		public:
		typedef bst_iterator<false>	iterator;
		typedef bst_iterator<true>	const_iterator;

		protected:
		node			*root;
		Compare			comp;

		node	*_insert(const T &val, node * &subtreeRoot, node *parent) {
			if (subtreeRoot == NULL) {
				subtreeRoot = new node(val, NULL, NULL, parent);
				return subtreeRoot;
			}
			else if (comp(val, subtreeRoot->value))
				return this->_insert(val, subtreeRoot->left, subtreeRoot);
			else if (comp(subtreeRoot->value, val))
				return this->_insert(val, subtreeRoot->right, subtreeRoot);
			else
				return NULL;
		};

		bool	_remove(const T &val, node * &subtreeRoot) {
			if (subtreeRoot == NULL)
				return false;
			if (comp(val, subtreeRoot->value))
				return this->_remove(val, subtreeRoot->left);
			if (comp(subtreeRoot->value, val))
				return this->_remove(val, subtreeRoot->right);
			if (subtreeRoot->left != NULL && subtreeRoot->right != NULL) {
				node *min = this->findMin(subtreeRoot->right);
				node *newParent = new node(min->value, subtreeRoot->left, subtreeRoot->right, subtreeRoot->parent);
				delete subtreeRoot;
				subtreeRoot = newParent;
				this->_remove(subtreeRoot->value, subtreeRoot->right);
				return true;
			}
			else {
				node *toBeDeleted = subtreeRoot;
				subtreeRoot = (subtreeRoot->left != NULL) ? subtreeRoot->left : subtreeRoot->right;
				if (subtreeRoot != NULL)
					subtreeRoot->parent = toBeDeleted->parent;
				delete toBeDeleted;
				return true;
			}
		};

		node	*_clone(node *subtreeRoot) const {
			if (subtreeRoot == NULL)
				return NULL;
			else
				return new node(subtreeRoot->value, this->_clone(subtreeRoot->left),
				this->_clone(subtreeRoot->right), subtreeRoot->parent);
		};

		void	_print(node *subtreeRoot) const {
			if (subtreeRoot == NULL)
			{
				std::cout << std::endl;
				return;
			}
			this->_print(subtreeRoot->left);
			std::cout << subtreeRoot->value << " " << std::endl;
			this->_print(subtreeRoot->right);
		};

		void	_clear(node * &subtreeRoot) {
			if (subtreeRoot != NULL) {
				this->_clear(subtreeRoot->left);
				this->_clear(subtreeRoot->right);
				delete subtreeRoot;
			}
			subtreeRoot = NULL;
		};

		public:
		bs_tree(const Compare& compare = std::less<T>()) : root(NULL), comp(compare) {};
		bs_tree(node *root, const Compare& compare = std::less<T>()) : root(root), comp(compare) {};
		bs_tree(const tree &other, const Compare& compare = std::less<T>()) : root(NULL), comp(compare) {
			this->root = this->_clone(other.root); //TOOD check what's wrong with clone, why adding two values
		};
		virtual ~bs_tree() {
			this->clear();
		};

		bs_tree	&operator=(const tree &other) {
			this->clear(this->root);
			this->root = this->_clone(other.root);
			this->comp = other.comp;
			return *this;
		};

		bool	empty() const { return this->root == NULL; };
		node	*getRoot() { return this->root; };

		void	clear() { 
			this->_clear(this->root);
		};

		node	*findMin(node *subtreeRoot) const {
			if (subtreeRoot != NULL) {
				while (subtreeRoot->left != NULL)
				subtreeRoot = subtreeRoot->left;
			}
			return subtreeRoot;
		};

		node	*findMax(node *subtreeRoot) const {
			if (subtreeRoot != NULL) {
				while (subtreeRoot->right != NULL)
				subtreeRoot = subtreeRoot->right;
			}
			return subtreeRoot, this;
		};

		iterator	find(const T &val) const {
			node *res = this->root;
			while (res != NULL) {
				if (!comp(res->value, val) && !comp(val, res->value)) 
					return iterator(res, this);
				res = (comp(val, res->value)) ? res->left : res->right;
			}
			return this->end();
		};

		iterator	insert(const T &val) { 
			node *res = this->_insert(val, this->root, NULL);
			if (!res) { return this->end(); }
			return iterator(res, this);
		};

		bool		remove(const T &val) {
			return this->_remove(val, this->root);
		}

		iterator	begin() const { 
			return iterator(this->findMin(this->root), this);
		};
		const_iterator	cbegin() const {
			return const_iterator(this->findMin(this->root), this);
		};

		iterator	end() const { 
			return iterator(NULL, this);
		};
		const_iterator	cend() const {
			return const_iterator(NULL, this);
		};

		size_t		max_size() const { return std::allocator<bst_node<T> >().max_size(); }

		void		swap(bs_tree &x) { 
			bst_node<T>	*tmpRoot = this->root;
			Compare compObj = this->comp;

			this->root = x.root;
			this->comp = x.comp;
			x.root = tmpRoot;
			x.comp = compObj;
		};

		void		print() const {
			this->_print(this->root);
		};
	};

	template <class T, class Compare>
	bool	operator==(const bs_tree<T,Compare>& lhs, const bs_tree<T,Compare>& rhs) {
		typename bs_tree<T,Compare>::iterator itl = lhs.begin();
		typename bs_tree<T,Compare>::iterator itr = rhs.begin();
		for (; itl != lhs.end(); ++itl, ++itr) {
			if (*itl != *itr) { return false; }
		}
		return true;
	};

	template <class T, class Compare>
	bool	operator!=(const bs_tree<T,Compare>& lhs, const bs_tree<T,Compare>& rhs) {
		return !(rhs == lhs);
	};	

	template <class T, class Compare>
	bool	operator<(const bs_tree<T,Compare>& lhs, const bs_tree<T,Compare>& rhs) {
		typename bs_tree<T,Compare>::iterator first1 = lhs.begin();
		typename bs_tree<T,Compare>::iterator first2 = rhs.begin();
		typename bs_tree<T,Compare>::iterator last1 = lhs.end();
		typename bs_tree<T,Compare>::iterator last2 = rhs.end();
		for (; first1 != last1; first1++, first2++) {
			if (first2 == last2 || (*first2 < *first1)) { return false; }
			else if (*first1 < *first2) { return true; }
		}
		return (*first2 != *last2);
	};

	template <class T, class Compare>
	bool	operator<=(const bs_tree<T,Compare>& lhs, const bs_tree<T,Compare>& rhs) {
		return !(lhs > rhs);
	};

	template <class T, class Compare>
	bool	operator>(const bs_tree<T,Compare>& lhs, const bs_tree<T,Compare>& rhs) {
		return (rhs < lhs);
	};

	template <class T, class Compare>
	bool	operator>=(const bs_tree<T,Compare>& lhs, const bs_tree<T,Compare>& rhs) {
		return !(lhs < rhs);
	};
}

#endif //__FT_BST_H__