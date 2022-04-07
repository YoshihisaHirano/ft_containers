#include "rbt.hpp"
#include "set.hpp"

int main()
{
	ft::rbt_node<int> *node = new ft::rbt_node<int>(9);
	ft::rb_tree<int> mytree(node);
	ft::rb_tree<int> anothertree = mytree;
	ft::set<int> myset;
	return 0;
}
