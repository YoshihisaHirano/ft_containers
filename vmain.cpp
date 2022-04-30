#include "vector.hpp"
#include "iterator.hpp"
#include <iostream>
#include <vector>
#include <type_traits>
#include "is_integral.hpp"
#include "pair.hpp"
#include "equal.hpp"
// struct s_time_res	t_res;

// time_t timer();
// void print_res(std::string test, std::vector<int> &s,
// 		std::vector<int> &u, struct s_time_res &res);
// void print_header();

// void stack_test(void);
// void pair_test(void);
// void map_test(void);

void vector_test(void);

bool mypredicate (int i, int j) {
	return (i==j);
}

int main()
{
	{
	std::cout << "___ft___" << std::endl;
	ft::vector<int> vect;
	for (int i = 0; i < 10; i++)
		vect.push_back(i);
	ft::vector<int>	vect1(vect);
	vect.push_back(78);
	vect.push_back(12);
	vect.push_back(78);
	vect.push_back(12);
	vect.push_back(78);
	vect.push_back(12);
	std::cout << "size: " << vect.size() << " capacity "  << vect.capacity() << 
	" back: " << vect.back() << " front: " << vect.front()  << std::endl;
	vect1.pop_back();
	vect1.pop_back();
	std::cout << "erase res: " << *(vect1.erase(vect1.begin() + 1, vect1.begin() + 3)) << std::endl;
	std::cout << "erase res2: " << *(vect1.erase(vect1.begin() + 1, vect1.end() - 4)) << std::endl;
	std::cout << "erase res3: " << *(vect1.erase(vect1.begin() + 3)) << std::endl;
	std::cout << "size: " << vect1.size() << " capacity " << vect1.capacity() << 
	" back: " << vect1.back() << " front: " << vect1.front()  << std::endl;

	ft::vector<int> myvector (3,100);
	std::cout << "myvector size: " << myvector.size() << " capacity "  << myvector.capacity() << std::endl;
	ft::vector<int>::iterator it;
	it = myvector.begin();
	std::cout << "myvector size: " << myvector.size() << " capacity "  << myvector.capacity() << std::endl;
	it = myvector.insert ( it, 200 );
	// myvector.reserve(91);
	std::cout << "after insertion - size: " << myvector.size() << " capacity "  << myvector.capacity() << 
	" back: " << myvector.back() << " front: " << myvector.front()  << std::endl;
	for (size_t i = 0; i < myvector.size(); i++) {
		std::cout << myvector[i] << " ";
	}
	std::cout << std::endl;
	myvector.insert (it,2,300);
	for (size_t j = 0; j < myvector.size(); j++) {
		std::cout << myvector[j] << " ";
	}
	std::cout << std::endl;
	}
	{
	std::cout << "___std___" << std::endl;
	std::vector<int> vect;
	for (int i = 0; i < 10; i++)
		vect.push_back(i);
	std::vector<int> vect1(vect);
	vect.push_back(78);
	vect.push_back(12);
	vect.push_back(78);
	vect.push_back(12);
	vect.push_back(78);
	vect.push_back(12);
	std::cout << "size: " << vect.size() << " capacity "  << vect.capacity() << 
	" back: " << vect.back() << " front: " << vect.front()  << std::endl;
	vect1.pop_back();
	vect1.pop_back();
	std::cout << "erase res: " << *(vect1.erase(vect1.begin() + 1, vect1.begin() + 3)) << std::endl;
	std::cout << "erase res2: " << *(vect1.erase(vect1.begin() + 1, vect1.end() - 4)) << std::endl;
	std::cout << "erase res3: " << *(vect1.erase(vect1.begin() + 3)) << std::endl;
	std::cout << "size: " << vect1.size() << " capacity " << vect1.capacity() << 
	" back: " << vect1.back() << " front: " << vect1.front()  << std::endl;

	std::vector<int> myvector (3,100);
	std::cout << "myvector size: " << myvector.size() << " capacity "  << myvector.capacity() << std::endl;
	std::vector<int>::iterator it;
	it = myvector.begin();
	std::cout << "myvector size: " << myvector.size() << " capacity "  << myvector.capacity() << std::endl;
	it = myvector.insert ( it, 200 );
	std::cout << "after insertion - size: " << myvector.size() << " capacity "  << myvector.capacity() << 
	" back: " << myvector.back() << " front: " << myvector.front()  << std::endl;
	for (size_t i = 0; i < myvector.size(); i++) {
		std::cout << myvector[i] << " ";
	}
	std::cout << std::endl;
	myvector.insert (it,2,300);
	for (size_t j = 0; j < myvector.size(); j++) {
		std::cout << myvector[j] << " ";
	}
	std::cout << std::endl;
	}
	// std::vector<int>::iterator it = vect.begin();
	// std::vector<int>::iterator ite = vect.end();

	// std::vector<int> second(6);
	// std::cout << second.size() << " size " << second.capacity() << " capacity" << std::endl;
	// try {
	// 	second.assign(0, 8);
	// 	std::cout << second.size() << " size " << second.capacity() << " capacity" << std::endl;
	// } catch (const std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }


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
	{
	std::cout << "___std____" << std::endl;
	std::vector<int> avect(10, 33);
	std::vector<int> otherVect(3, 100);
	std::vector<int> thirdVect(22, 88);

	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	avect.push_back(67);
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	avect.assign(5, 90);
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	avect = otherVect;
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;

	std::vector<int>::iterator it = otherVect.begin();
	std::vector<int>::iterator ite = otherVect.end();
	avect.assign(it, ite);
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	avect.assign(thirdVect.begin(), thirdVect.end());
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	}

	{
	std::cout << "___ft____" << std::endl;
	ft::vector<int> avect(10, 33);
	ft::vector<int> otherVect(3, 100);
	ft::vector<int> thirdVect(22, 88);

	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	avect.push_back(67);
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	avect.assign(5, 90);
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	avect = otherVect;
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	ft::vector<int>::iterator it = otherVect.begin();
	ft::vector<int>::iterator ite = otherVect.end();
	avect.assign(it, ite);
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	avect.assign(thirdVect.begin(), thirdVect.end());
	std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	}

	{
		std::cout << std::boolalpha;
		std::cout << "_____is_integral______" << std::endl;
		std::cout << "std char: " << std::is_integral<char>::value << std::endl;
		std::cout << "ft char: " << ft::is_integral<char>::value << std::endl;
		std::cout << "std int: " << std::is_integral<int>::value << std::endl;
		std::cout << "ft int: " << ft::is_integral<int>::value << std::endl;
		std::cout << "std float: " << std::is_integral<float>::value << std::endl;
		std::cout << "ft float: " << ft::is_integral<float>::value << std::endl;
		std::cout << "std std::vector<int>: " << std::is_integral<std::vector<int> >::value << std::endl;
		std::cout << "ft std::vector<int>: " << ft::is_integral<std::vector<int> >::value << std::endl;
	}

	{
		std::cout << "______pair_______" << std::endl;
		std::pair <int,int> foo;
		std::cout << "std first: " << foo.first << " second: " << foo.second << std::endl;
		ft::pair <int,int> ffoo;
		std::cout << "ft first: " << ffoo.first << " second: " << ffoo.second << std::endl;

		ft::pair <std::string,double> product1;                     // default constructor
  		ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  		ft::pair <std::string,double> product3 (product2);          // copy constructor

  		product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair

  		product2.first = "shoes";                  // the type of first is string
  		product2.second = 39.90;                   // the type of second is double

		std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	}

	{
		std::cout << "______equal_______" << std::endl;
		// int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
  		// ft::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100
		ft::vector<int> myvector(5, 10);
		ft::vector<int> myints(5, 10);

  		// using default comparison:
		if ( ft::equal (myvector.begin(), myvector.end(), myints.begin()) )
		std::cout << "The contents of both sequences are equal.\n";
		else
		std::cout << "The contents of both sequences differ.\n";

  		myvector[3]=81;                                 // myvector: 20 40 60 81 100

  		// using predicate comparison:
		if ( ft::equal (myvector.begin(), myvector.end(), myints.begin(), mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
		else
		std::cout << "The contents of both sequences differ.\n";
	}

	{
		std::cout << "______vector.swap_______" << std::endl;
		ft::vector<int> foo (3,100);   // three ints with a value of 100
  		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << " " << foo[i];
		std::cout << std::endl;

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << " " << bar[i];
		std::cout << std::endl;
	}
	// try {
	// 	vector_test();
	// } catch (const std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }

	vector_test();
	// {
	// 	std::vector<int> vecta;
	// 	// ft::vector<int> vectb;

	// 	std::cout << "std: " << vecta[0] << std::endl;
	// 	std::cout << "std: " << vecta.front() << std::endl;
	// 	std::cout << "std: " << vecta.back() << std::endl;
	// 	std::cout << "std: " << vecta.at(3) << std::endl;
	// }
	return 0;
}
