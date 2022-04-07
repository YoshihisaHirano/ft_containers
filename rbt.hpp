#ifndef _FT_RBT_H__
#define _FT_RBT_H__
#include "bst.hpp"

namespace ft {
	template <typename T>
	struct rbt_node : public bst_node<T> {
		typedef rbt_node* node;

		bool	isRed;

		rbt_node(T value, node lt = NULL, node rt = NULL, node pt = NULL)
		: bst_node<T>(value, lt, rt, pt), isRed(0) {};
	};

	template <typename T, class Compare = std::less<T> > // TODO: balancing methods
	class rb_tree : public bs_tree<T, Compare> {
		protected:
		typedef rbt_node<T>			node;
		typedef rb_tree<T, Compare>	tree;
		typedef bs_tree<T,Compare>	bs_tree;

		public:
		typedef typename bs_tree::iterator			iterator;
		typedef typename bs_tree::const_iterator	const_iterator;

		rb_tree(const Compare& compare = std::less<T>()) : bs_tree(compare) {};
		rb_tree(node *root, const Compare& compare = std::less<T>()) 
		: bs_tree(root, compare) {};
		rb_tree(const tree &other, const Compare& compare = std::less<T>()) : bs_tree(other, compare) {};
		virtual ~rb_tree() {
			bs_tree::clear();
		};

		rb_tree &operator=(const tree & other) {
			bs_tree::operator=(other);
			return *this;
		};
	};
};

#endif // __RBT_H__