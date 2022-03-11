#include "vector.hpp"
#include "iterator.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "hi" << std::endl;
	std::vector<int> vect;
	// std::vector<int>::iterator it = vect.begin();
	// std::vector<int>::iterator ite = vect.end();

	std::vector<int> second(6);
	std::cout << second.size() << " size " << second.capacity() << " capacity" << std::endl;
	try {
		second.assign(0, 8);
		std::cout << second.size() << " size " << second.capacity() << " capacity" << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	// std::vector<int> first;	
	// std::vector<int> second;	
	// std::vector<int> third;
	
	// first.assign (7,100);             // 7 ints with a value of 100
	
	// std::vector<int>::iterator it;	
	// it=first.begin()+1;
	
	// second.assign (it,first.end()-1); // the 5 central values of first
	
	// int myints[] = {1776,7,4};	
	// third.assign (myints,myints+3);   // assigning from array.
	
	// std::cout << "Size of first: " << int (first.size()) << '\n';	
	// std::cout << "Size of second: " << int (second.size()) << '\n';	
	// std::cout << "Size of third: " << int (third.size()) << '\n';

	return 0;
}