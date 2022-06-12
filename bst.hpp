#ifndef __FT_BST_H__
#define __FT_BST_H__
#include <memory>
#include <exception>
#include <iostream>
#include <iterator>
#include "iterator.hpp"
#include "utility.hpp"

namespace ft {
	template <typename T>
	struct bst_node
	{
		typedef bst_node* node;

		T			value;
		node		left;
		node		right;
		node		parent;
		bool		red;

		bst_node(T value, node lt = NULL, node rt = NULL, node pt = NULL, bool red = true)
		: value(value), left(lt), right(rt), parent(pt), red(red) {};
	};

	template <bool isConst, typename T>
	class bst_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	public:
	typedef bst_node<T> Node;

	private:
	Node		*position;
	Node		*tree_root;

	public:
	typedef typename ft::conditional<isConst, const T&, T&>::type	reference;
	typedef typename ft::conditional<isConst, const T*, T*>::type   pointer;

	bst_iterator() : position(NULL), tree_root(NULL) {};
	bst_iterator(const bst_iterator& other) : position(other.position), tree_root(other.tree_root) {};
	bst_iterator(Node *pos, Node *tr) : position(pos), tree_root(tr) {};
	~bst_iterator() {};
	template <bool B, typename U>
	bst_iterator(const bst_iterator<B, U> & x, typename ft::enable_if<!B>::type* = 0) {
		this->position = x.getPos();
		this->tree_root = x.getTreeRoot();
	};

	bst_iterator	&operator=(const bst_iterator& other) {
		this->position = other.position;
		this->tree_root = other.tree_root;
		return *this;
	};

	Node	*getTreeRoot() const { return this->tree_root; }
	Node	*getPos() const { return this->position; }

	reference			operator*() { return this->position->value; };
	pointer				operator->() { return &(this->position->value); };

	bst_iterator		&operator++() {
		if (this->tree_root == NULL) {
			throw std::underflow_error("Trying to increment over an empty tree");
		}
		if (this->position->right != NULL) {
			this->position = this->position->right;
			while (this->position->left != NULL)
				this->position = this->position->left;
		} else {
			Node	*tmp = this->position->parent;
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
		if (this->tree_root == NULL) {
			throw std::underflow_error("Trying to decrement over an empty tree");
		}
		if (this->position == NULL) {
			this->position = this->tree_root;
			while (this->position->right != NULL) 
				this->position = this->position->right;
		}
		else if (this->position->left != NULL) {
			this->position = this->position->left;
			while (this->position->right != NULL) 
				this->position = this->position->right;
		}
		else {
			Node	*tmp = this->position->parent;
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
		return (rhs.position == this->position && rhs.tree_root == this->tree_root);
	};

	bool operator!=(const bst_iterator& rhs) const {
		return !(rhs.operator==(*this));
	};
};

	template <typename T, class Compare = std::less<T> >
	class bs_tree {
		protected:
		typedef bst_node<T>			node;
		typedef bs_tree<T, Compare>	tree;

		public:
		typedef bst_iterator<false, T>	iterator;
		typedef bst_iterator<true, T>	const_iterator;

		private:
		node			*root;
		Compare			comp;

		node	*_insert(const T &val) {
			node *newNode = new node(val, NULL, NULL, NULL);
			node *x = this->root;
			node *y = NULL;
			while (x != NULL) {
				y = x;
				if (comp(val, x->value))
					x = x->left;
				else
					x = x->right;
			}
			newNode->parent = y;
			if (newNode->parent == NULL) {
				this->root = newNode;
				return newNode;
			}
			if (comp(val, y->value))
				y->left = newNode;
			else
				y->right = newNode;
			return newNode;
		};

		node	*_insert_rb(const T &val, node * &subtreeRoot, node *parent) {
			node *newNode = this->_insert(val);
			if (newNode->parent == NULL || newNode->parent->parent == NULL)
				return newNode;
			this->_preserve_balance(newNode);
			return newNode;
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

	public: //to delete

		void	print_tree(node *subRoot, std::string indent, bool last) {
			if (subRoot != NULL) {
				std::cout << indent;
				if (last) {
					std::cout<<"R----";
					indent += "     ";
				} else {
					std::cout<<"L----";
					indent += "|    ";
				}
				std::string sColor = subRoot->red ? "RED" : "BLACK";
				std::cout<< subRoot->value.first << "(" <<sColor<< ")" << std::endl;
				print_tree(subRoot->left, indent, false);
				print_tree(subRoot->right, indent, true);
			}
		};

		void prettyPrint() {
			if (this->root) {
				print_tree(this->root, "", true);
			}
		};

	private:

		void	_preserve_balance(node *x) {
			node *uncle;
			while(x->parent && x->parent->red) {
				if (x->parent == x->parent->parent->right) {
					uncle = x->parent->parent->left;
					if (uncle && uncle->red) {
						uncle->red = false;
						x->parent->red = false;
						x->parent->parent->red = true;
						x = x->parent->parent;
					} else {
						if (x == x->parent->left) {
							x = x->parent;
							_rightRotate(x);
						}
						x->parent->red = false;
						x->parent->parent->red = true;
						_leftRotate(x->parent->parent);
					}
				} else {
					uncle = x->parent->parent->right;
					if (uncle && uncle->red) {
						uncle->red = false;
						x->parent->red = false;
						x->parent->parent->red = true;
						x = x->parent->parent;
					} else {
						if (x == x->parent->right) {
							x = x->parent;
							_leftRotate(x);
						}
						x->parent->red = false;
						x->parent->parent->red = true;
						_rightRotate(x->parent->parent);
					}
				}
				if(x == this->root)
					break;
			}
			this->root->red = false;
		}

		void	_clear(node *subtreeRoot) {
			if (subtreeRoot == NULL)
				return;
			this->_clear(subtreeRoot->left);
			this->_clear(subtreeRoot->right);
			delete subtreeRoot;
			subtreeRoot = NULL;
		};

		void	_leftRotate(node *x) {
			if (x->right == NULL) return;
			node *y = x->right;
			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		};

		void	_rightRotate(node *x) {
			if (x->left == NULL) return;
			node *y = x->left;
			x->left = y->right;
			if (y->right != NULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->right = x;
			x->parent = y;
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
			this->clear();
			this->root = this->_clone(other.root);
			this->comp = other.comp;
			return *this;
		};

		bool	empty() const { return this->root == NULL; };
		node	*getRoot() { return this->root; };

		void	clear() { 
			this->_clear(this->root);
			this->root = NULL;
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
			return subtreeRoot;
		};

		iterator	find(const T &val) const {
			node *res = this->root;
			while (res != NULL) {
				if (!comp(res->value, val) && !comp(val, res->value)) 
					return iterator(res, this->root);
				res = (comp(val, res->value)) ? res->left : res->right;
			}
			return this->end();
		};

		iterator	insert(const T &val) { 
			node *res = this->_insert_rb(val, this->root, NULL);
			if (!res) { return this->end(); }
			return iterator(res, this->root);
		};

		bool		remove(const T &val) {
			return this->_remove(val, this->root);
		}

		iterator	begin() const { 
			return iterator(this->findMin(this->root), this->root);
		};
		const_iterator	cbegin() const {
			return const_iterator(this->findMin(this->root), this->root);
		};

		iterator	end() const { 
			return iterator(NULL, this->root);
		};
		const_iterator	cend() const {
			return const_iterator(NULL, this->root);
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