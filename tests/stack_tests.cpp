#include <unistd.h>
#include <sys/time.h>
#include <stack>
#include <vector>
#include <iomanip>
#include <iterator>
#include "../stack.hpp"
#include "../vector.hpp"


static void construct_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;

	V.push_back(st.size());
	V.push_back(st.empty());

	res.ft_end = timer();
}

static void construct_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;

	V.push_back(st.size());
	V.push_back(st.empty());

	res.std_end = timer();
}


static void empty_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.empty());
	st.pop();
	st.pop();
	V.push_back(st.empty());

	res.ft_end = timer();
}

static void empty_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.empty());
	st.pop();
	st.pop();
	V.push_back(st.empty());

	res.std_end = timer();
}


static void size_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.top());
	V.push_back(st.size());
	st.pop();
	st.pop();
	V.push_back(st.size());

	for (int i = 0; i < 100000; i++)
		st.push(i);
	V.push_back(st.size());

	res.ft_end = timer();
}

static void size_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.top());
	V.push_back(st.size());
	st.pop();
	st.pop();
	V.push_back(st.size());

	for (int i = 0; i < 100000; i++)
		st.push(i);
	V.push_back(st.size());

	res.std_end = timer();
}


static void top_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.top());
	V.push_back(st.size());
	st.pop();
	V.push_back(st.size());
	V.push_back(st.top());
	V.push_back(st.top());

	for (int i = 0; i < 100000; i++)
		st.push(i);
	V.push_back(st.size());
	V.push_back(st.top());

	res.ft_end = timer();
}

static void top_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.top());
	V.push_back(st.size());
	st.pop();
	V.push_back(st.size());
	V.push_back(st.top());
	V.push_back(st.top());

	for (int i = 0; i < 100000; i++)
		st.push(i);
	V.push_back(st.size());
	V.push_back(st.top());

	res.std_end = timer();
}

static void push_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.top());
	V.push_back(st.size());
	st.pop();
	V.push_back(st.size());
	V.push_back(st.top());
	V.push_back(st.top());

	for (int i = 0; i < 100000; i++)
		st.push(i);
	V.push_back(st.size());
	V.push_back(st.top());

	res.ft_end = timer();
}

static void push_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.top());
	V.push_back(st.size());
	st.pop();
	V.push_back(st.size());
	V.push_back(st.top());
	V.push_back(st.top());

	for (int i = 0; i < 100000; i++)
		st.push(i);


	res.std_end = timer();
}


static void pop_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.top());
	V.push_back(st.size());
	st.pop();
	V.push_back(st.size());
	V.push_back(st.top());
	V.push_back(st.top());

	for (int i = 0; i < 100000; i++)
		st.push(i);
	V.push_back(st.size());
	V.push_back(st.top());
	while(!st.empty())
		st.pop();
	V.push_back(st.size());


	res.ft_end = timer();
}

static void pop_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;
	V.push_back(st.size());
	V.push_back(st.empty());
	st.push(42);
	st.push(42);
	V.push_back(st.top());
	V.push_back(st.size());
	st.pop();
	V.push_back(st.size());
	V.push_back(st.top());
	V.push_back(st.top());

	for (int i = 0; i < 100000; i++)
		st.push(i);
	V.push_back(st.size());
	V.push_back(st.top());
	while(!st.empty())
		st.pop();
	V.push_back(st.size());

	res.std_end = timer();
}


static void operator_eq_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st == st2);
	st.push(42);
	st.push(42);
	V.push_back(st == st2);
	st.pop();
	st.pop();
	V.push_back(st == st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st == st2);
	while(!st.empty())
		st.pop();
	V.push_back(st == st2);


	res.ft_end = timer();
}

static void operator_eq_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st == st2);
	st.push(42);
	st.push(42);
	V.push_back(st == st2);
	st.pop();
	st.pop();
	V.push_back(st == st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st == st2);
	while(!st.empty())
		st.pop();
	V.push_back(st == st2);

	res.std_end = timer();
}


static void operator_not_eq_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st != st2);
	st.push(42);
	st.push(42);
	V.push_back(st != st2);
	st.pop();
	st.pop();
	V.push_back(st != st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st != st2);
	while(!st.empty())
		st.pop();
	V.push_back(st != st2);


	res.ft_end = timer();
}

static void operator_not_eq_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st != st2);
	st.push(42);
	st.push(42);
	V.push_back(st != st2);
	st.pop();
	st.pop();
	V.push_back(st != st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st != st2);
	while(!st.empty())
		st.pop();
	V.push_back(st != st2);

	res.std_end = timer();
}


static void operator_less_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st < st2);
	st.push(42);
	st.push(42);
	V.push_back(st < st2);
	st.pop();
	st.pop();
	V.push_back(st < st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st < st2);
	while(!st.empty())
		st.pop();
	V.push_back(st < st2);


	res.ft_end = timer();
}

static void operator_less_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st < st2);
	st.push(42);
	st.push(42);
	V.push_back(st < st2);
	st.pop();
	st.pop();
	V.push_back(st < st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st < st2);
	while(!st.empty())
		st.pop();
	V.push_back(st < st2);

	res.std_end = timer();
}


static void operator_less_eq_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st <= st2);
	st.push(42);
	st.push(42);
	V.push_back(st <= st2);
	st.pop();
	st.pop();
	V.push_back(st <= st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st <= st2);
	while(!st.empty())
		st.pop();
	V.push_back(st <= st2);


	res.ft_end = timer();
}

static void operator_less_eq_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();
	_stack	st;
	_stack	st2;
	V.push_back(st <= st2);
	st.push(42);
	st.push(42);
	V.push_back(st <= st2);
	st.pop();
	st.pop();
	V.push_back(st <= st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st <= st2);
	while(!st.empty())
		st.pop();
	V.push_back(st <= st2);

	res.std_end = timer();
}


static void operator_more_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st > st2);
	st.push(42);
	st.push(42);
	V.push_back(st > st2);
	st.pop();
	st.pop();
	V.push_back(st > st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st > st2);
	while(!st.empty())
		st.pop();
	V.push_back(st > st2);


	res.ft_end = timer();
}

static void operator_more_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();
	_stack	st;
	_stack	st2;
	V.push_back(st > st2);
	st.push(42);
	st.push(42);
	V.push_back(st > st2);
	st.pop();
	st.pop();
	V.push_back(st > st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st > st2);
	while(!st.empty())
		st.pop();
	V.push_back(st > st2);

	res.std_end = timer();
}

static void operator_more_eq_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::stack<int> _stack;

	res.ft_start = timer();

	_stack	st;
	_stack	st2;
	V.push_back(st >= st2);
	st.push(42);
	st.push(42);
	V.push_back(st >= st2);
	st.pop();
	st.pop();
	V.push_back(st >= st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st >= st2);
	while(!st.empty())
		st.pop();
	V.push_back(st >= st2);


	res.ft_end = timer();
}

static void operator_more_eq_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::stack<int> _stack;

	res.std_start = timer();
	_stack	st;
	_stack	st2;
	V.push_back(st >= st2);
	st.push(42);
	st.push(42);
	V.push_back(st >= st2);
	st.pop();
	st.pop();
	V.push_back(st >= st2);

	for (int i = 0; i < 100000; i++)
		st.push(i);
	for (int i = 0; i < 100000; i++)
		st2.push(i);
	V.push_back(st >= st2);
	while(!st.empty())
		st.pop();
	V.push_back(st >= st2);

	res.std_end = timer();
}

//----------------------------------------------------
void stack_test(void)
{
	std::vector<int>	s;
	std::vector<int>	u;
	struct s_time_res	t_res;

	std::cout << "*********************************************************************" << std::endl;
	std::cout << "*                               STACK                               *" << std::endl;
	std::cout << "*********************************************************************" << std::endl;

	print_header();

	construct_test_u(u, t_res);
	construct_test_s(s, t_res);
	print_res("Construct", s, u, t_res);
	u.clear();
	s.clear();

	empty_test_u(u, t_res);
	empty_test_s(s, t_res);
	print_res("Empty", s, u, t_res);
	u.clear();
	s.clear();

	size_test_u(u, t_res);
	size_test_s(s, t_res);
	print_res("Size", s, u, t_res);
	u.clear();
	s.clear();

	top_test_u(u, t_res);
	top_test_s(s, t_res);
	print_res("Top", s, u, t_res);
	u.clear();
	s.clear();

	push_test_u(u, t_res);
	push_test_s(s, t_res);
	print_res("Push", s, u, t_res);
	u.clear();
	s.clear();

	pop_test_u(u, t_res);
	pop_test_s(s, t_res);
	print_res("Pop", s, u, t_res);
	u.clear();
	s.clear();

	operator_eq_test_u(u, t_res);
	operator_eq_test_s(s, t_res);
	print_res("==", s, u, t_res);
	u.clear();
	s.clear();

	operator_not_eq_test_u(u, t_res);
	operator_not_eq_test_s(s, t_res);
	print_res("!=", s, u, t_res);
	u.clear();
	s.clear();

	operator_less_test_u(u, t_res);
	operator_less_test_s(s, t_res);
	print_res("<", s, u, t_res);
	u.clear();
	s.clear();


	operator_less_eq_test_u(u, t_res);
	operator_less_eq_test_s(s, t_res);
	print_res("<=", s, u, t_res);
	u.clear();
	s.clear();

	operator_more_test_u(u, t_res);
	operator_more_test_s(s, t_res);
	print_res(">", s, u, t_res);
	u.clear();
	s.clear();

	operator_more_eq_test_u(u, t_res);
	operator_more_eq_test_s(s, t_res);
	print_res(">=", s, u, t_res);
	u.clear();
	s.clear();
}