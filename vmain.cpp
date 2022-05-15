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

template <typename T>
std::vector<int> insert_test_2(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	vector.insert(vector.end() - 50, 4200 * 1000 , 2);
	v.push_back(vector[2121]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> insert_test_2(ft::vector<T> vector) {
	std::vector<int> v;
	vector.assign(1000, 1);
	vector.insert(vector.end() - 50, 4200 * 1000 , 2);
	v.push_back(vector[2121]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

int main()
{
	{
		ft::vector<int> myvect;
		std::vector<int> thevect;
		std::vector<int> mine = insert_test_2(myvect);
		std::vector<int> correct = insert_test_2(thevect);
//		std::cout << mine.size() << std::endl;

		for (unsigned i=0; i<mine.size(); i++)
			std::cout << " " << mine[i];
		std::cout << std::endl;
		for (unsigned j=0; j<correct.size(); j++)
			std::cout << " " << correct[j];
	}
	return 0;
}
