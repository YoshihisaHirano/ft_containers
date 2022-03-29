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

		bst_node(T value, bst_node *lt, bst_node *rt, bst_node *pt)
		: value(value), left(lt), right(rt), parent(pt) {};
	};

	template <typename T>
	class bst_iterator : public iterator_traits<T*> {
		private:
		friend class bs_tree<T>;

		bst_node<T>	*position;
		bs_tree<T>	*tree;
		bst_iterator(const bst_node<T> pos, const bs_tree tr) : position(pos), tree(tr) {};

		public:
		typedef typename iterator_traits<T*>::reference			reference;

		bst_iterator() : position(NULL), tree(NULL) {};
		bst_iterator(const bst_iterator& other) : position(other.position), tree(other.tree) {};
		~bst_iterator() {};

		const bst_node<T>		*getPosition() const { return this->position; }

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
				bst_node<T>	*tmp = this->position;
				while (this->position->parent != NULL) {
					this->position = this->position->parent;
					if (tmp == this->position->left)
						break;
					else 
						tmp = this->position;
				}
				if (this->position->parent == NULL)
					return bst_iterator(NULL, this->tree);
			}
			return *this;
		}
	};

	template <typename T>
	bool operator==(const bst_iterator<T>& lhs, const bst_iterator<T>& rhs) {
		return (rhs.getPosition() == lhs.getPosition());
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

		public:
		bs_tree() : root(NULL) {};
		bs_tree(node *root) : root(root) {};
		bs_tree(const bs_tree &other) {}; // clone instruction
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
			node *res = this->root;
			while (res != NULL)
				res = res->left;
			return (res);
		};

		node	*findMax() {
			node *res = this->root;
			while (res != NULL)
				res = res->right;
			return (res);
		};

		const_iterator	begin() const { 
			return bst_iterator(this->findMin(), this);
		};

		const_iterator	end() const { 
			return bst_iterator(NULL, this);
		};
	};
	
}

#endif //__FT_BST_H__