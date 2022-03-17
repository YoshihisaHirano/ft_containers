#include "vector.hpp"
#include "iterator.hpp"
#include <iostream>
#include <vector>

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
	// avect = otherVect;
	// std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;

	// std::vector<int>::iterator it = otherVect.begin();
	// std::vector<int>::iterator ite = otherVect.end();
	// avect.assign(it, ite);
	// std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	// avect.assign(thirdVect.begin(), thirdVect.end());
	// std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
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
	// avect = otherVect;
	// std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	// ft::vector<int>::iterator it = otherVect.begin();
	// ft::vector<int>::iterator ite = otherVect.end();
	// avect.assign(it, ite);
	// std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	// avect.assign(thirdVect.begin(), thirdVect.end());
	// std::cout << "size: " << avect.size() << " capacity "  << avect.capacity() << " back: " << avect.back() << std::endl;
	}
	return 0;
}
