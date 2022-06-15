#include <unistd.h>
#include <sys/time.h>
#include <stack>
#include <vector>
#include <iomanip>
#include <iterator>
#include "../stack.hpp"
#include "../vector.hpp"
#include "../utility.hpp"

static void construct_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::pair<int, int> _pair;

	res.ft_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);

	V.push_back(pr.first);
	V.push_back(pr.second);
	V.push_back(pr2.first);
	V.push_back(pr2.second);
	V.push_back(pr3.first);
	V.push_back(pr3.second);
	res.ft_end = timer();
}

static void construct_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;

	res.std_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);

	V.push_back(pr.first);
	V.push_back(pr.second);
	V.push_back(pr2.first);
	V.push_back(pr2.second);
	V.push_back(pr3.first);
	V.push_back(pr3.second);

	res.std_end = timer();
}


static void operator_assign_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::pair<int, int> _pair;

	res.ft_start = timer();

	_pair	pr;
	_pair	pr2 = pr;
	_pair	pr3(pr);

	V.push_back(pr2.first);
	V.push_back(pr2.second);

	pr3 = pr2;
	V.push_back(pr3.first);
	V.push_back(pr3.second);


	res.ft_end = timer();
}

static void operator_assign_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;

	res.std_start = timer();

	_pair	pr;
	_pair	pr2 = pr;
	_pair	pr3(pr);

	V.push_back(pr2.first);
	V.push_back(pr2.second);

	pr3 = pr2;
	V.push_back(pr3.first);
	V.push_back(pr3.second);



	res.std_end = timer();
}




static void operator_eq_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::pair<int, int> _pair;

	res.ft_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);V.push_back(pr != pr2);
	V.push_back(pr2 == pr3);
	V.push_back(pr3 == pr);
	V.push_back(pr2 == pr4);
	V.push_back(pr5 == pr2);


	res.ft_end = timer();
}

static void operator_eq_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;


	res.std_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);V.push_back(pr != pr2);
	V.push_back(pr2 == pr3);
	V.push_back(pr3 == pr);
	V.push_back(pr2 == pr4);
	V.push_back(pr5 == pr2);

	res.std_end = timer();
}


static void operator_not_eq_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::pair<int, int> _pair;

	res.ft_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);V.push_back(pr != pr2);
	V.push_back(pr2 != pr3);
	V.push_back(pr3 != pr);
	V.push_back(pr2 != pr4);
	V.push_back(pr5 != pr2);

	res.ft_end = timer();
}

static void operator_not_eq_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;


	res.std_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);V.push_back(pr != pr2);
	V.push_back(pr2 != pr3);
	V.push_back(pr3 != pr);
	V.push_back(pr2 != pr4);
	V.push_back(pr5 != pr2);
	res.std_end = timer();
}


static void operator_less_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::pair<int, int> _pair;

	res.ft_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);
	V.push_back(pr < pr2);
	V.push_back(pr2 < pr3);
	V.push_back(pr3 < pr);
	V.push_back(pr2 < pr4);
	V.push_back(pr5 < pr2);


	res.ft_end = timer();
}

static void operator_less_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;


	res.std_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);
	V.push_back(pr < pr2);
	V.push_back(pr2 < pr3);
	V.push_back(pr3 < pr);
	V.push_back(pr2 < pr4);
	V.push_back(pr5 < pr2);

	res.std_end = timer();
}


static void operator_less_eq_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::pair<int, int> _pair;

	res.ft_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);
	V.push_back(pr <= pr2);
	V.push_back(pr2 <= pr3);
	V.push_back(pr3 <= pr);
	V.push_back(pr2 <= pr4);
	V.push_back(pr5 <= pr2);


	res.ft_end = timer();
}

static void operator_less_eq_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;


	res.std_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);
	V.push_back(pr <= pr2);
	V.push_back(pr2 <= pr3);
	V.push_back(pr3 <= pr);
	V.push_back(pr2 <= pr4);
	V.push_back(pr5 <= pr2);

	res.std_end = timer();
}


static void operator_more_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::pair<int, int> _pair;

	res.ft_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);
	V.push_back(pr > pr2);
	V.push_back(pr2 > pr3);
	V.push_back(pr3 > pr);
	V.push_back(pr2 > pr4);
	V.push_back(pr5 > pr2);


	res.ft_end = timer();
}

static void operator_more_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;


	res.std_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);
	V.push_back(pr > pr2);
	V.push_back(pr2 > pr3);
	V.push_back(pr3 > pr);
	V.push_back(pr2 > pr4);
	V.push_back(pr5 > pr2);

	res.std_end = timer();
}

static void operator_more_eq_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;


	res.std_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);
	V.push_back(pr >= pr2);
	V.push_back(pr2 >= pr3);
	V.push_back(pr3 >= pr);
	V.push_back(pr2 >= pr4);
	V.push_back(pr5 >= pr2);

	res.std_end = timer();
}

static void operator_more_eq_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;


	res.std_start = timer();

	_pair	pr;
	_pair	pr2(42, 21);
	_pair	pr3(pr2);
	_pair	pr4(42, 20);
	_pair	pr5(40, 21);
	V.push_back(pr >= pr2);
	V.push_back(pr2 >= pr3);
	V.push_back(pr3 >= pr);
	V.push_back(pr2 >= pr4);
	V.push_back(pr5 >= pr2);

	res.std_end = timer();
}

static void make_pair_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::pair<int, int> _pair;

	res.ft_start = timer();

	_pair	pr = ft::make_pair(123, 321);
	_pair	pr2 = ft::make_pair(42, 21);

	V.push_back(pr.first);
	V.push_back(pr.second);
	V.push_back(pr2.first);
	V.push_back(pr2.second);


	res.ft_end = timer();
}

static void make_pair_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::pair<int, int> _pair;

	res.std_start = timer();

	_pair	pr = std::make_pair(123, 321);
	_pair	pr2 = std::make_pair(42, 21);

	V.push_back(pr.first);
	V.push_back(pr.second);
	V.push_back(pr2.first);
	V.push_back(pr2.second);

	res.std_end = timer();
}

//----------------------------------------------------
void pair_test(void)
{
	std::vector<int>	s;
	std::vector<int>	u;
	struct s_time_res	t_res;

	std::cout << "********************************************************************" << std::endl;
	std::cout << "*                               PAIR                               *" << std::endl;
	std::cout << "********************************************************************" << std::endl;

	print_header();

	construct_test_u(u, t_res);
	construct_test_s(s, t_res);
	print_res("Construct", s, u, t_res);
	u.clear();
	s.clear();

	operator_assign_test_u(u, t_res);
	operator_assign_test_s(s, t_res);
	print_res("operator=", s, u, t_res);
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

	make_pair_test_u(u, t_res);
	make_pair_test_s(s, t_res);
	print_res("make_pair", s, u, t_res);
	u.clear();
	s.clear();
}