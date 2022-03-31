#include "map.hpp"
#include <iostream>

int main()
{
	ft::map<int, int> mymap;
	mymap.begin();
	mymap.end();
	std::cout << "mymap is empty: " << mymap.empty() << std::endl;
	return 0;
}
