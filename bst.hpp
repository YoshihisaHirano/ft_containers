#ifndef __FT_BST_H__
#define __FT_BST_H__
#include <memory>
#include <exception>
#include "iterator.hpp"

namespace ft {
	template <typename T>
	struct bst_node
	{
		T			value;
		bst_node	*left;
		bst_node	*right;
		bst_node	*parent;

		bst_node(T value, bst_node *lt = NULL, bst_node *rt = NULL, bst_node *pt = NULL)
		: value(value), left(lt), right(rt), parent(pt) {};
	};

	template <typename T>
	class bst_iterator : public iterator_traits<T*> {
		private:
		friend class bs_tree<T>;
		friend bool operator==(const bst_iterator<T>& lhs, const bst_iterator<T>& rhs);

		bst_node<T>	*position;
		bs_tree<T>	*tree;
		bst_iterator(const bst_node<T> pos, const bs_tree tr) : position(pos), tree(tr) {};

		public:
		typedef typename iterator_traits<T*>::reference			reference;

		bst_iterator() : position(NULL), tree(NULL) {};
		bst_iterator(const bst_iterator& other) : position(other.position), tree(other.tree) {};
		~bst_iterator() {};

		bst_iterator	&operator=(const bst_iterator& other) {
			this->position = other.position;
			this->tree = other.tree;
			return *this;
		};

		const reference		operator*() const { return this->position->value; };
		const bst_node<T>	*operator->() const { return this->position; };

		bst_iterator		&operator++() {
			if (this->tree.empty()) {
				throw std::underflow_error("Trying to increment over an empty tree");
			}
			if (this->position->right != NULL) {
				this->position = this->position->right;
				while (this->position->left ! = NULL)
					this->position = this->position->left;
			} else {
				bst_node<T>	*tmp = this->position->parent;
				while (tmp != NULL && this->position == tmp->right) { 
					this->position = tmp;
					tpm = tmp->parent;
				}
				this->position = tmp;
			}
			return *this;
		};

		bst_iterator		&operator++(int) {
			bst_iterator temp = *this;
			this->operator++();
			return temp;
		};

		bst_iterator		&operator--() {
			if (this->tree.empty()) {
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
					tpm = tmp->parent;
				}
				this->position = tmp;
			}
			return *this;
		};

		bst_iterator		&operator--(int) {
			bst_iterator temp = *this;
			this->operator--();
			return temp;
		};
	};

	template <typename T>
	bool operator==(const bst_iterator<T>& lhs, const bst_iterator<T>& rhs) {
		return (rhs.position == lhs.position && rhs.tree == lhs.tree);
	};

	template <typename T>
	bool operator!=(const bst_iterator<T>& lhs, const bst_iterator<T>& rhs) {
		return !(rhs == lhs);
	};

	template <typename T>
	class bs_tree {
		public:
		typedef bst_node<T>		node;
		typedef bst_iterator<T>	const_iterator;
		typedef const_iterator	iterator;

		private:
		node	*root;

		node	*_insert(const T &val, node *subtreeRoot, node *parent) {
			if (subtreeRoot == NULL) {
				subtreeRoot = new bst_node(val, NULL, NULL, parent);
				return subtreeRoot;
			}
			else if (val < subtreeRoot->value)
				return this->_insert(val, subtreeRoot->left, subtreeRoot);
			else if (val > subtreeRoot->value)
				return this->_insert(val, subtreeRoot->right, subtreeRoot);
			else
				return NULL;
		};

		bool	_remove(const T &val, node *subtreeRoot) {
			if (subtreeRoot == NULL)
				return false;
			if (val < subtreeRoot->value)
				return this->_remove(val, subtree->left);
			if (val > subtreeRoot->value)
				return this->_remove(val, subtree->right);
			if (subtreeRoot->left != NULL && subtreeRoot->right != NULL) {
				subtreeRoot->value = this->findMin(subtreeRoot->right)->value;
				this->_remove(subtreeRoot->value, subtreeRoot->right);
				return true;
			}
			else {
				node *toBeDeleted = subtreeRoot;
				subtreeRoot = (subtreeRoot->left != NULL) ? subtreeRoot->left : subtreeRoot->right;
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

		public:
		bs_tree() : root(NULL) {};
		bs_tree(node *root) : root(root) {};
		bs_tree(const bs_tree &other) {
			this->root = this->_clone(other.root);
		};
		~bs_tree() {
			this->clear(this->root);
		};

		bool	empty() const { return this->root == NULL; };

		void	clear(node *rootNode) { 
			if (rootNode != NULL) {
				clear(rootNode->left);
				clear(rootNode->right);
				delete rootNode; // maybe allocator?
			}
			rootNode = NULL;
		};

		node	*findMin() {
			if (this->empty())
				throw std::underflow_error("The tree is empty!");
			node *res = this->root;
			while (res != NULL)
				res = res->left;
			return (res);
		};

		node	*findMax() {
			if (this->empty())
				throw std::underflow_error("The tree is empty!");
			node *res = this->root;
			while (res != NULL)
				res = res->right;
			return (res);
		};

		const node	*find(const T &val) const {
			node *res = this->root;
			while (res != NULL || res->value != val) {
				res = (res->value < val) res->left : res->right;
			}
			return res;
		};

		const_iterator	insert(const T &val) { 
			node *res = this->_insert(val, this->root, NULL);
			if (!res) { return this->end(); }
			return bst_iterator(res, this);
		};

		void			remove(const T &val) {
			this->_remove(val, this->root);
		}

		const_iterator	begin() const { 
			return bst_iterator(this->findMin(), this);
		};

		const_iterator	end() const { 
			return bst_iterator(NULL, this);
		};
	};
	
}

#endif //__FT_BST_H__