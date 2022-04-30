#include <unistd.h>
#include <sys/time.h>
#include <stack>
#include <vector>
#include <iomanip>
#include <iterator>
#include "./stack.hpp"
#include "./vector.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

// for tests

struct s_time_res
{
	time_t std_start;
	time_t std_end;
	time_t ft_start;
	time_t ft_end;
}  ;
// struct s_time_res	t_res;

// time_t timer();
// void print_res(std::string test, std::vector<int> &s,
// 		std::vector<int> &u, struct s_time_res &res);
// void print_header();

// void vector_test(void);
// void stack_test(void);
// void pair_test(void);
// void map_test(void);
// void set_test(void);

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}


void print_res(std::string test, std::vector<int> &s,
		std::vector<int> &u, struct s_time_res &res)
{
	time_t s_time = res.std_end - res.std_start;
	time_t u_time = res.ft_end - res.ft_start;
	std::vector<int> error_res;
	
	std::string std_time_color = s_time <= u_time ? GREEN : RED;
	std::string ft_time_color = u_time <= s_time ? GREEN : RED;

	bool is_correct = true;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] != u[i])
		{
			error_res.push_back(s[i]);
			error_res.push_back(u[i]);
			error_res.push_back(i + 1);
			is_correct = false;
		}
	}

	std::string resultText = is_correct ? "OK" : "FALSE";
	std::cout
		<< std::setw(30) << std::setfill(' ') << std::left << test << (is_correct ? GREEN : RED)
		<< std::setw(10) << std::setfill(' ') << std::left << resultText << RESET 
		<< ft_time_color << std::setw(15) << std::setfill(' ') << std::left << u_time << RESET
		<< std_time_color << std::setw(15) << std::setfill(' ') << std::left << s_time << RESET
		
		<< std::endl;

	if (!is_correct)
	{
		std::cout << "Incorrect results for " << test << " on test # " << error_res[2] << std::endl;
		std::cout << "std: " << error_res[0] << std::endl;
		std::cout << "ft: " << error_res[1] << std::endl;
	}
}

void print_header()
{

	std::cout
		<< std::setw(30) << std::setfill(' ') << std::left << "FUNCTION" 
		<< std::setw(10) << std::setfill(' ') << std::left << "RESULT"
		<< std::setw(15) << std::setfill(' ') << std::left << "FT_TIME"
		<< std::setw(15) << std::setfill(' ') << std::left << "STD_TIME"
		
		<< std::endl;
}

int ratio = 10000;

void construct_test_u(std::vector<int> &U, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;
	res.ft_start = timer();

	// default
	_vector		u;
	U.push_back(u.size());
	U.push_back(u.capacity());

	// n and val
	_vector		u1(1100);
	U.push_back(u1[42]);
	_vector		u2(100, 42);
	U.push_back(u2[42]);
	U.push_back(u2.size());
	U.push_back(u2.capacity());

	// range
	_vector		u3(u2.begin(), u2.begin() + 42);
	U.push_back(u3[21]);
	U.push_back(u3.size());
	U.push_back(u3.capacity());


	// copy
	_vector		u4(u3);
	U.push_back(u4[21]);
	U.push_back(u4.size());
	U.push_back(u4.capacity());

	// =operator
	_vector		u5 = u3;

	_vector		u6;
	u6= u3;

	res.ft_end = timer();
}

void construct_test_s(std::vector<int> &U, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
		// default
	_vector		u;
	U.push_back(u.size());
	U.push_back(u.capacity());

	// n and val
	_vector		u1(1100);
	U.push_back(u1[42]);
	_vector		u2(100, 42);
	U.push_back(u2[42]);
	U.push_back(u2.size());
	U.push_back(u2.capacity());

	// range
	_vector		u3(u2.begin(), u2.begin() + 42);
	U.push_back(u3[21]);
	U.push_back(u3.size());
	U.push_back(u3.capacity());


	// copy
	_vector		u4(u3);
	U.push_back(u4[21]);
	U.push_back(u4.size());
	U.push_back(u4.capacity());

	// =operator
	_vector		u5 = u3;

	_vector		u6;
	u6 = u3;
	res.std_end = timer();
}

void begin_test_s(std::vector<int> &U, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
		// default
	_vector		u;

	for (int i = 0; i < 100; i++)
		u.push_back(i);
	U.push_back(*(u.begin()));
	U.push_back(*(u.begin() + 42));
	_vector::iterator it = u.begin() + 42;
	it++;
	++it;
	++it;
	it--;
	--it;
	U.push_back(*it);



	res.std_end = timer();
}

void begin_test_u(std::vector<int> &U, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
		// default
	_vector		u;

	for (int i = 0; i < 100; i++)
		u.push_back(i);
	U.push_back(*(u.begin()));
	U.push_back(*(u.begin() + 42));
	_vector::iterator it = u.begin() + 42;
	it++;
	++it;
	++it;
	it--;
	--it;
	U.push_back(*it);


	res.ft_end = timer();
}

void end_test_s(std::vector<int> &U, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
		// default
	_vector		u;

	for (int i = 0; i < 100; i++)
		u.push_back(i);
	U.push_back(*(u.end() - 1));
	U.push_back(*(u.end() - 42));

	_vector::iterator it = u.end() - 42;
	it++;
	++it;
	++it;
	it--;
	--it;
	U.push_back(*it);


	res.std_end = timer();
}

void end_test_u(std::vector<int> &U, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
		// default
	_vector		u;

	for (int i = 0; i < 100; i++)
		u.push_back(i);
	U.push_back(*(u.end() - 1));
	U.push_back(*(u.end() - 42));
	_vector::iterator it = u.end() - 42;
	it++;
	++it;
	++it;
	it--;
	--it;
	U.push_back(*it);


	res.ft_end = timer();
}

void rbegin_test_s(std::vector<int> &U, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
		// default
	_vector		u;

	for (int i = 0; i < 100; i++)
		u.push_back(i);
	U.push_back(*(u.rbegin()));
	U.push_back(*(u.rbegin() + 42));

	_vector::reverse_iterator it = u.rbegin() + 42;
	it++;
	++it;
	++it;
	it--;
	--it;
	U.push_back(*it);



	res.std_end = timer();
}

void rbegin_test_u(std::vector<int> &U, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
		// default
	_vector		u;

	for (int i = 0; i < 100; i++)
		u.push_back(i);
	U.push_back(*(u.rbegin()));
	U.push_back(*(u.rbegin() + 42));

	_vector::reverse_iterator it = u.rbegin() + 42;
	it++;
	++it;
	++it;
	it--;
	--it;
	U.push_back(*it);

	res.ft_end = timer();
}

void rend_test_s(std::vector<int> &U, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();

	_vector		u;

	for (int i = 0; i < 100; i++)
		u.push_back(i);
	U.push_back(*(u.rend() + 1));
	U.push_back(*(u.rend() + 42));

	_vector::reverse_iterator it = u.rend() - 42;
	it++;
	++it;
	++it;
	it--;
	--it;
	U.push_back(*it);
	res.std_end = timer();
}

void rend_test_u(std::vector<int> &U, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();

	_vector		u;

	for (int i = 0; i < 100; i++)
		u.push_back(i);
	U.push_back(*(u.rend() + 1));
	U.push_back(*(u.rend() + 42));
	_vector::reverse_iterator it = u.rend() - 42;
	it++;
	++it;
	++it;
	it--;
	--it;
	U.push_back(*it);

	res.ft_end = timer();
}


void size_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.pop_back();
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.clear();
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void size_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.pop_back();
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.clear();
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.std_end = timer();
}


void max_size_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	
	V.push_back(v.max_size());
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.pop_back();
	V.push_back(v.max_size());
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.clear();
	V.push_back(v.max_size());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void max_size_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	
	V.push_back(v.max_size());
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.pop_back();
	V.push_back(v.max_size());
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.clear();
	V.push_back(v.max_size());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.std_end = timer();
}


void resize_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;
	v.resize(0);
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.resize(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.resize(100, 21);
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.resize(1000, 99);
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void resize_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
		v.resize(0);
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.resize(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.resize(100, 21);
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.resize(1000, 99);
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.std_end = timer();
}


void reserve_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;
	v.reserve(0);
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(100);
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.reserve(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void reserve_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	v.reserve(0);
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(100);
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.reserve(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.std_end = timer();
}


void capacity_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;
	v.reserve(0);
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(100);
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.reserve(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void capacity_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	v.reserve(0);
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(100);
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.reserve(1000);
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.std_end = timer();
}


void empty_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;
	V.push_back(v.empty());
	v.reserve(0);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(1000);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.clear();
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void empty_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	V.push_back(v.empty());
	v.reserve(0);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.reserve(1000);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.clear();
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.std_end = timer();
}

void access_operator_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(v[0]);
	V.push_back(v[1]);
	V.push_back(v[42]);

	v.clear();
	V.push_back(v[0]);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void access_operator_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(v[0]);
	V.push_back(v[1]);
	V.push_back(v[42]);

	v.clear();
	V.push_back(v[0]);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.std_end = timer();
}

void at_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(v.at(0));
	V.push_back(v.at(1));
	V.push_back(v.at(42));

	v.clear();
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void at_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(v.at(0));
	V.push_back(v.at(1));
	V.push_back(v.at(42));

	v.clear();
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	res.std_end = timer();
}

void front_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(v.front());

	v.clear();
	V.push_back(v.front());
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void front_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(v.front());

	v.clear();
	V.push_back(v.front());
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	res.std_end = timer();
}


void back_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	
	_vector		v;

	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(v.back());
	V.pop_back();
	V.push_back(v.back());

	v.clear();
	V.push_back(v.back());
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void back_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(v.back());
	V.pop_back();
	V.push_back(v.back());

	v.clear();
	V.push_back(v.back());
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	res.std_end = timer();
}


void assign_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	


	_vector		v;
	v.assign(1000, 42);
	V.push_back(v.back());
	V.push_back(v[42]);
	V.push_back(v.front());
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.clear();
	for (int i = 0; i < 10 * ratio; i++)
		v.push_back(i);
	_vector		v2;
	v2.assign(v.begin(), v.begin() + ratio);
	V.push_back(v2.back());
	V.push_back(v2[42]);
	V.push_back(v2.front());
	V.push_back(v2.empty());
	V.push_back(v2.size());
	V.push_back(v2.capacity());

	v2.assign(10, 21);
	V.push_back(v2.back());
	V.push_back(v2[2]);
	V.push_back(v2.front());
	V.push_back(v2.empty());
	V.push_back(v2.size());
	V.push_back(v2.capacity());


	res.ft_end = timer();
}

void assign_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	v.assign(1000, 42);
	V.push_back(v.back());
	V.push_back(v[42]);
	V.push_back(v.front());
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());
	v.clear();
	for (int i = 0; i < 10 * ratio; i++)
		v.push_back(i);
	_vector		v2;
	v2.assign(v.begin(), v.begin() + ratio);
	V.push_back(v2.back());
	V.push_back(v2[42]);
	V.push_back(v2.front());
	V.push_back(v2.empty());
	V.push_back(v2.size());
	V.push_back(v2.capacity());

	v2.assign(10, 21);
	V.push_back(v2.back());
	V.push_back(v2[2]);
	V.push_back(v2.front());
	V.push_back(v2.empty());
	V.push_back(v2.size());
	V.push_back(v2.capacity());

	res.std_end = timer();
}

void push_back_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();

	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);
	v.clear();
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);
	V.push_back(v.back());
	V.push_back(v[2]);
	V.push_back(v.front());
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void push_back_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);
	v.clear();
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);
	V.push_back(v.back());
	V.push_back(v[2]);
	V.push_back(v.front());
	V.push_back(v.empty());
	V.push_back(v.size());
	V.push_back(v.capacity());

	res.std_end = timer();
}

void pop_back_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();

	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);
	while(!v.empty())
		v.pop_back();
	V.push_back(v.back());
	V.push_back(v.front());
	V.push_back(v.size());
	V.push_back(v.capacity());


	res.ft_end = timer();
}

void pop_back_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);
	while(!v.empty())
		v.pop_back();
	V.push_back(v.back());
	V.push_back(v.front());
	V.push_back(v.size());
	V.push_back(v.capacity());

	res.std_end = timer();
}

void insert_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();

	_vector		v;

	v.insert(v.begin(), 42);
	V.push_back(v.front());
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);
	v.insert(v.begin() + 1000, 42);
	v.insert(v.end() - 1, 42);
	V.push_back(*(v.begin() + 1000));
	V.push_back(v.back());
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.insert(v.begin() + 100, ratio, 21);
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(*(v.begin() + 100));

	_vector		v2;

	v2.insert(v2.begin(), v.begin() + 1000, v.end());

	V.push_back(v2.size());
	V.push_back(v2.capacity());
	V.push_back(*(v2.begin() + 100));
	res.ft_end = timer();
}

void insert_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	v.insert(v.begin(), 42);
	V.push_back(v.front());
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);
	v.insert(v.begin() + 1000, 42);
	v.insert(v.end() - 1, 42);
	V.push_back(*(v.begin() + 1000));
	V.push_back(v.back());
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.insert(v.begin() + 100, ratio, 21);
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(*(v.begin() + 100));

	_vector		v2;

	v2.insert(v2.begin(), v.begin() + 1000, v.end());

	V.push_back(v2.size());
	V.push_back(v2.capacity());
	V.push_back(*(v2.begin() + 100));
	

	res.std_end = timer();
}

void erase_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();

	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);

	V.push_back( *(v.erase(v.begin() + 1000)));
	V.push_back(*(v.begin() + 1000));
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.erase(v.end() - 1);
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(*(v.begin() + 100));


	v.erase(v.begin(), v.begin() + 1000);
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(*(v.begin()));

	V.push_back( *(v.erase(v.begin(), v.end())));
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(*(v.begin()));
	res.ft_end = timer();
}

void erase_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);

	V.push_back( *(v.erase(v.begin() + 1000)));
	V.push_back(*(v.begin() + 1000));
	V.push_back(v.size());
	V.push_back(v.capacity());

	v.erase(v.end() - 1);
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(*(v.begin() + 100));


	v.erase(v.begin(), v.begin() + 1000);
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(*(v.begin()));

	V.push_back( *(v.erase(v.begin(), v.end())));
	V.push_back(v.size());
	V.push_back(v.capacity());
	V.push_back(*(v.begin()));

	res.std_end = timer();
}


void swap_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();

	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 1000; i < 1000 * ratio; i++)
		v2.push_back(i);

	v.swap(v2);
	V.push_back(*(v.begin() + 1000));
	V.push_back(v.size());
	V.push_back(v.capacity());

	V.push_back(*(v2.begin() + 1000));
	V.push_back(v2.size());
	V.push_back(v2.capacity());



	res.ft_end = timer();
}

void swap_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 1000; i < 1000 * ratio; i++)
		v2.push_back(i);

	v.swap(v2);
	V.push_back(*(v.begin() + 1000));
	V.push_back(v.size());
	V.push_back(v.capacity());

	V.push_back(*(v2.begin() + 1000));
	V.push_back(v2.size());
	V.push_back(v2.capacity());
	
	res.std_end = timer();
}


void clear_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();

	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 1000; i < 1000 * ratio; i++)
		v2.push_back(i);

	v.clear();
	V.push_back(*(v.begin()));
	V.push_back(v.size());
	V.push_back(v.capacity());

	v2.clear();
	V.push_back(*(v2.begin()));
	V.push_back(v2.size());
	V.push_back(v2.capacity());



	res.ft_end = timer();
}

void clear_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	
	_vector		v;
	for (int i = 0; i < 1000 * ratio; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 1000; i < 1000 * ratio; i++)
		v2.push_back(i);

	v.clear();
	V.push_back(*(v.begin()));
	V.push_back(v.size());
	V.push_back(v.capacity());

	v2.clear();
	V.push_back(*(v2.begin()));
	V.push_back(v2.size());
	V.push_back(v2.capacity());
	
	res.std_end = timer();
}

void operator_eq_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v == v2);
	v2.pop_back();
	V.push_back(v == v2);
	v.pop_back();
	V.push_back(v == v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v == v2);
	res.ft_end = timer();
}

void operator_eq_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v == v2);
	v2.pop_back();
	V.push_back(v == v2);
	v.pop_back();
	V.push_back(v == v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v == v2);
	res.std_end = timer();
}

void operator_not_eq_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v != v2);
	v2.pop_back();
	V.push_back(v != v2);
	v.pop_back();
	V.push_back(v != v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v != v2);
	res.ft_end = timer();
}

void operator_not_eq_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v != v2);
	v2.pop_back();
	V.push_back(v != v2);
	v.pop_back();
	V.push_back(v != v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v != v2);
	res.std_end = timer();
}

void operator_less_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v < v2);
	v2.pop_back();
	V.push_back(v < v2);
	v.pop_back();
	V.push_back(v < v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v < v2);
	res.ft_end = timer();
}

void operator_less_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v < v2);
	v2.pop_back();
	V.push_back(v < v2);
	v.pop_back();
	V.push_back(v < v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v < v2);
	res.std_end = timer();
}

void operator_less_eq_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;

	res.ft_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v <= v2);
	v2.pop_back();
	V.push_back(v <= v2);
	v.pop_back();
	V.push_back(v <= v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v <= v2);
	res.ft_end = timer();
}

void operator_less_eq_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v <= v2);
	v2.pop_back();
	V.push_back(v <= v2);
	v.pop_back();
	V.push_back(v <= v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v <= v2);
	res.std_end = timer();
}

void operator_more_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;
	
	res.std_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v > v2);
	v2.pop_back();
	V.push_back(v > v2);
	v.pop_back();
	V.push_back(v > v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v > v2);
	
	res.ft_end = timer();
}

void operator_more_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v > v2);
	v2.pop_back();
	V.push_back(v > v2);
	v.pop_back();
	V.push_back(v > v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v > v2);

	res.std_end = timer();
}


void operator_more_eq_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::vector<int> _vector;
	
	res.std_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v >= v2);
	v2.pop_back();
	V.push_back(v >= v2);
	v.pop_back();
	V.push_back(v >= v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v >= v2);
	
	res.ft_end = timer();
}

void operator_more_eq_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::vector<int> _vector;

	res.std_start = timer();
	_vector		v;
	for (int i = 0; i < 1000; i++)
		v.push_back(i);

	_vector		v2;
	for (int i = 0; i < 1000; i++)
		v2.push_back(i);
	V.push_back(v >= v2);
	v2.pop_back();
	V.push_back(v >= v2);
	v.pop_back();
	V.push_back(v >= v2);
	v.resize(200);
	v2.resize(200);
	V.push_back(v >= v2);

	res.std_end = timer();
}


//----------------------------------------------------
void vector_test(void)
{
	std::vector<int>	s;
	std::vector<int>	u;
	struct s_time_res	t_res;


	std::cout << "*********************************************************************" << std::endl;
	std::cout << "*                              VECTOR                               *" << std::endl;
	std::cout << "*********************************************************************" << std::endl;
	
	print_header();

	// construct_test_u(u, t_res);
	// construct_test_s(s, t_res);
	// print_res("Construct", s, u, t_res);
	// u.clear();
	// s.clear();

	begin_test_s(s, t_res);
	begin_test_u(u, t_res);
	print_res("Begin", s, u, t_res);
	u.clear();
	s.clear();

	end_test_s(s, t_res);
	end_test_u(u, t_res);
	print_res("End", s, u, t_res);
	u.clear();
	s.clear();

	rbegin_test_s(s, t_res);
	rbegin_test_u(u, t_res);
	print_res("Rbegin", s, u, t_res);
	u.clear();
	s.clear();

	rend_test_s(s, t_res);
	rend_test_u(u, t_res);
	print_res("End", s, u, t_res);
	u.clear();
	s.clear();

	end_test_s(s, t_res);
	end_test_u(u, t_res);
	print_res("Rend", s, u, t_res);
	u.clear();
	s.clear();

	size_test_s(s, t_res);
	size_test_u(u, t_res);
	print_res("Size", s, u, t_res);
	u.clear();
	s.clear();

	max_size_test_s(s, t_res);
	max_size_test_u(u, t_res);
	print_res("Max_size", s, u, t_res);
	u.clear();
	s.clear();

	resize_test_s(s, t_res);
	resize_test_u(u, t_res);
	print_res("Resize", s, u, t_res);
	u.clear();
	s.clear();


	reserve_test_s(s, t_res);
	reserve_test_u(u, t_res);
	print_res("Reserve", s, u, t_res);
	u.clear();
	s.clear();

	capacity_test_s(s, t_res);
	capacity_test_u(u, t_res);
	print_res("Capacity", s, u, t_res);
	u.clear();
	s.clear();

	empty_test_s(s, t_res);
	empty_test_u(u, t_res);
	print_res("Empty", s, u, t_res);
	u.clear();
	s.clear();


	access_operator_test_s(s, t_res);
	access_operator_test_u(u, t_res);
	print_res("operator[]", s, u, t_res);
	u.clear();
	s.clear();

	at_test_s(s, t_res);
	at_test_u(u, t_res);
	print_res("at", s, u, t_res);
	u.clear();
	s.clear();

	front_test_s(s, t_res);
	front_test_u(u, t_res);
	print_res("front", s, u, t_res);
	u.clear();
	s.clear();

	back_test_s(s, t_res);
	back_test_u(u, t_res);
	print_res("back", s, u, t_res);
	u.clear();
	s.clear();

	assign_test_s(s, t_res);
	assign_test_u(u, t_res);
	print_res("assign", s, u, t_res);
	u.clear();
	s.clear();

	push_back_test_s(s, t_res);
	push_back_test_u(u, t_res);
	print_res("push_back", s, u, t_res);
	u.clear();
	s.clear();

	pop_back_test_s(s, t_res);
	pop_back_test_u(u, t_res);
	print_res("pop_back", s, u, t_res);
	u.clear();
	s.clear();

	insert_test_s(s, t_res);
	insert_test_u(u, t_res);
	print_res("insert", s, u, t_res);
	u.clear();
	s.clear();

	erase_test_s(s, t_res);
	erase_test_u(u, t_res);
	print_res("erase", s, u, t_res);
	u.clear();
	s.clear();

	swap_test_s(s, t_res);
	swap_test_u(u, t_res);
	print_res("swap", s, u, t_res);
	u.clear();
	s.clear();

	clear_test_s(s, t_res);
	clear_test_u(u, t_res);
	print_res("clear", s, u, t_res);
	u.clear();
	s.clear();
	std::cout << "relational operators" << std::endl;

	operator_eq_s(s, t_res);
	operator_eq_u(u, t_res);
	print_res("==", s, u, t_res);
	u.clear();
	s.clear();


	operator_not_eq_s(s, t_res);
	operator_not_eq_u(u, t_res);
	print_res("!=", s, u, t_res);
	u.clear();
	s.clear();

	operator_less_s(s, t_res);
	operator_less_u(u, t_res);
	print_res("<", s, u, t_res);
	u.clear();
	s.clear();

	operator_less_eq_s(s, t_res);
	operator_less_eq_u(u, t_res);
	print_res("<=", s, u, t_res);
	u.clear();
	s.clear();

	operator_more_s(s, t_res);
	operator_more_u(u, t_res);
	print_res(">", s, u, t_res);
	u.clear();
	s.clear();

	operator_more_eq_s(s, t_res);
	operator_more_eq_u(u, t_res);
	print_res(">=", s, u, t_res);
	u.clear();
	s.clear();
}