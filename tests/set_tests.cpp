#include <unistd.h>
#include <sys/time.h>
#include <stack>
#include <map>
#include <vector>
#include <iomanip>
#include <iterator>
#include <set>
#include "../utility.hpp"
#include "../map.hpp"
#include "../set.hpp"

static void construct_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set st;
	for (int i = 0; i < 100; i++)
		st.insert(i);
	V.push_back(*(st.begin()));
	V.push_back(st.size());
	_set::iterator it = st.begin();
	for (; it != st.end(); it++)
		V.push_back(*it);

	_set st2(st);
	it = st2.begin();
	for (; it != st2.end(); it++)
		V.push_back(*it);
	V.push_back(st2.size());

	_set st3;
	st3 = st2;
	it = st3.begin();
	for (; it != st3.end(); it++)
		V.push_back(*it);
	V.push_back(st3.size());

	res.ft_end = timer();
}

static void construct_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set st;
	for (int i = 0; i < 100; i++)
		st.insert(i);
	V.push_back(*(st.begin()));
	V.push_back(st.size());
	_set::iterator it = st.begin();
	for (; it != st.end(); it++)
		V.push_back(*it);

	_set st2(st);
	it = st2.begin();
	for (; it != st2.end(); it++)
		V.push_back(*it);
	V.push_back(st.size());

	_set st3;
	st3 = st2;
	it = st3.begin();
	for (; it != st3.end(); it++)
		V.push_back(*it);
	V.push_back(st3.size());

	res.std_end = timer();
}

static void begin_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 1000; i++)
		m.insert(i);
	V.push_back(m.empty());
	V.push_back(m.size());
	_set::iterator it = m.begin();
	V.push_back(*it);
	++it;
	V.push_back(*it);
	_set::iterator it2 = m.begin();
	V.push_back(it == it2);
	_set::iterator it3 = it;
	V.push_back(it == it3);
	it++;
	V.push_back(*it);
	--it;
	V.push_back(*it);
	it--;
	V.push_back(*it);

	res.ft_end = timer();
}

static void begin_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 1000; i++)
		m.insert(i);
	V.push_back(m.empty());
	V.push_back(m.size());
	_set::iterator it = m.begin();
	V.push_back(*it);
	++it;
	V.push_back(*it);
	_set::iterator it2 = m.begin();
	V.push_back(it == it2);
	_set::iterator it3 = it;
	V.push_back(it == it3);
	it++;
	V.push_back(*it);
	--it;
	V.push_back(*it);
	it--;
	V.push_back(*it);

	res.std_end = timer();
}

static void end_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();


	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10000; i++)
		m.insert(i);
	V.push_back(m.empty());
	V.push_back(m.size());
	_set::iterator ite = m.end();
	ite--;
	V.push_back(*ite);
	--ite;
	V.push_back(*ite);
	_set m2;
	for (int i = 1; i < 10; i++)
		m2.insert(i);
	_set::iterator it = m2.begin();
	ite = m2.end();
	ite--;
	for (; it != ite; ite--)
		V.push_back(*ite);

	res.ft_end = timer();
}

static void end_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10000; i++)
		m.insert(i);
	V.push_back(m.empty());
	V.push_back(m.size());
	_set::iterator ite = m.end();
	ite--;
	V.push_back(*ite);
	--ite;
	V.push_back(*ite);
	_set m2;
	for (int i = 1; i < 10; i++)
		m2.insert(i);
	_set::iterator it = m2.begin();
	ite = m2.end();
	ite--;
	for (; it != ite; ite--)
		V.push_back(*ite);

	res.std_end = timer();
}


static void rbegin_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();


	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10000; i++)
		m.insert(i);
	_set::reverse_iterator it = m.rbegin();
	_set::reverse_iterator ite = m.rend();
	it++;
	V.push_back(*it);
	for (; it != ite; it++)
		V.push_back(*it);


	res.ft_end = timer();
}

static void rbegin_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10000; i++)
		m.insert(i);
	_set::reverse_iterator it = m.rbegin();
	_set::reverse_iterator ite = m.rend();
	it++;
	V.push_back(*it);
	for (; it != ite; it++)
		V.push_back(*it);

	res.std_end = timer();
}

static void rend_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();


	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10000; i++)
		m.insert(i);
	_set::reverse_iterator it = m.rbegin();
	_set::reverse_iterator ite = m.rend();
	it++;
	V.push_back(*it);
	for (; it != ite; it++)
		V.push_back(*it);


	res.ft_end = timer();
}

static void rend_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10000; i++)
		m.insert(i);
	_set::reverse_iterator it = m.rbegin();
	_set::reverse_iterator ite = m.rend();
	it++;
	V.push_back(*it);
	for (; it != ite; it++)
		V.push_back(*it);

	res.std_end = timer();
}


static void empty_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	V.push_back(m.empty());

	for (int i = 0; i < 10; i++)
		m.insert(i);
	V.push_back(m.empty());
	m.clear();
	V.push_back(m.empty());

	res.ft_end = timer();
}

static void empty_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.empty());

	for (int i = 0; i < 10; i++)
		m.insert(i);
	V.push_back(m.empty());
	m.clear();
	V.push_back(m.empty());

	res.std_end = timer();
}



static void size_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	V.push_back(m.size());
	for (int i = 0; i < 100; i++)
		m.insert(i);
	V.push_back(m.size());
	m.clear();
	V.push_back(m.size());

	res.ft_end = timer();
}

static void size_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.size());
	for (int i = 0; i < 100; i++)
		m.insert(i);
	V.push_back(m.size());
	m.clear();
	V.push_back(m.size());

	res.std_end = timer();
}

static void insert_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();


	_set m;
	V.push_back(m.empty());
	for (int i = 0; i < 1000; i++)
		m.insert(i * 100);
	V.push_back(m.insert(100).second);
	V.push_back(m.insert(1000000).second);
	_set m2;
	m2.insert(m.begin(), m.end());
	V.push_back(m2.size());
	_set m3(m2);
	m3.insert(12);
	_set::iterator it = m3.find(12);
	m3.insert(it, 13);

	_set st;
	it = st.end();
	for (int i = 0; i < 5000; ++i) {
		st.insert(it, i);
	}
	_set::iterator it2 = st.begin();
	for (; it2 != st.end(); ++it2) {
		V.push_back(*it2);
	}


	res.ft_end = timer();
}

static void insert_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 0; i < 1000; i++)
		m.insert(i * 100);

	V.push_back(m.insert(100).second);
	V.push_back(m.insert(1000000).second);

	_set m2;
	m2.insert(m.begin(), m.end());
	V.push_back(m2.size());

	_set m3(m2);
	m3.insert(12);
	_set::iterator it = m3.find(12);
	m3.insert(it, 13);

	_set st;
	it = st.end();
	for (int i = 0; i < 5000; ++i) {
		st.insert(it, i);
	}
	_set::iterator it2 = st.begin();
	for (; it2 != st.end(); ++it2) {
		V.push_back(*it2);
	}
	res.std_end = timer();
}


static void erase_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10; i++)
		m.insert(i);
	m.erase( (m.begin()) );
	V.push_back(m.size());
	_set::iterator it = m.begin();
	it++;
	it++;
	m.erase( it );
	V.push_back(m.size());
	it = m.begin();
	for (; it != m.end(); it++)
		V.push_back(*it);
	m.erase(6);
	m.erase(7);
	for (; it != m.end(); it++)
		V.push_back(*it);
	it = m.begin();
	it++;
	it++;
	it++;
	m.erase(m.begin(), it);
	for (; it != m.end(); it++)
		V.push_back(*it);
	V.push_back(m.size());
	_set m2(m);
	it = m2.begin();
	m2.erase(7);
	it = m2.begin();
	for (; it != m2.end(); it++)
		V.push_back(*it);

	res.ft_end = timer();
}

static void erase_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10; i++)
		m.insert(i);
	m.erase( (m.begin()) );
	V.push_back(m.size());
	_set::iterator it = m.begin();
	it++;
	it++;
	m.erase( it );
	V.push_back(m.size());
	it = m.begin();
	for (; it != m.end(); it++)
		V.push_back(*it);
	m.erase(6);
	m.erase(7);
	for (; it != m.end(); it++)
		V.push_back(*it);
	it = m.begin();
	it++;
	it++;
	it++;
	m.erase(m.begin(), it);
	for (; it != m.end(); it++)
		V.push_back(*it);
	V.push_back(m.size());
	_set m2(m);
	it = m2.begin();
	m2.erase(7);
	it = m2.begin();
	for (; it != m2.end(); it++)
		V.push_back(*it);
	res.std_end = timer();
}


static void swap_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	_set m2;
	for (int i = 1; i < 10; i++)
		m.insert(i);
	for (int i = 1; i < 10; i++)
		m2.insert(i);
	m.swap(m2);
	V.push_back(m.size());
	V.push_back(m2.size());
	_set::iterator it = m.begin();
	for (; it != m.end(); it++)
		V.push_back(*it);
	it = m2.begin();
	for (; it != m2.end(); it++)
		V.push_back(*it);

	res.ft_end = timer();
}

static void swap_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;
	(void) V;

	res.std_start = timer();

	_set m;
	_set m2;
	for (int i = 1; i < 10; i++)
		m.insert(i);
	for (int i = 1; i < 10; i++)
		m2.insert(i);
	m.swap(m2);
	V.push_back(m.size());
	V.push_back(m2.size());
	_set::iterator it = m.begin();
	for (; it != m.end(); it++)
		V.push_back(*it);
	it = m2.begin();
	for (; it != m2.end(); it++)
		V.push_back(*it);

	res.std_end = timer();
}

static void clear_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10; i++)
		m.insert(i);
	m.clear();
	V.push_back(m.size());

	res.ft_end = timer();
}

static void clear_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	V.push_back(m.empty());
	for (int i = 1; i < 10; i++)
		m.insert(i);
	m.clear();
	V.push_back(m.size());

	res.std_end = timer();
}

static void key_comp_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int, std::greater<int> >  _set;

	res.ft_start = timer();

	_set myset;
	int highest;
	_set::key_compare mycomp = myset.key_comp();
	for (int i=0; i<=5; i++) myset.insert(i);
	highest = *(myset.rbegin());
	_set::iterator it=myset.begin();
	do {
		V.push_back(*it);
	} while ( mycomp(*(++it),highest) );

	res.ft_end = timer();
}

static void key_comp_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int, std::greater<int> > _set;

	res.std_start = timer();

	_set myset;
	int highest;
	_set::key_compare mycomp = myset.key_comp();
	for (int i=0; i<=5; i++) myset.insert(i);
	highest = *(myset.rbegin());
	_set::iterator it=myset.begin();
	do {
		V.push_back(*it);
	} while ( mycomp(*(++it),highest) );

	res.std_end = timer();
}


static void value_comp_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int, std::greater<int> >  _set;

	res.ft_start = timer();

	_set myset;
	_set::value_compare mycomp = myset.value_comp();
	for (int i=0; i<=5; i++) myset.insert(i);
	int highest = *(myset.rbegin());
	_set::iterator it=myset.begin();
	do {
		V.push_back(*it);
	}
	while ( mycomp(*(++it),highest) );

	res.ft_end = timer();
}

static void value_comp_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int, std::greater<int> > _set;

	res.std_start = timer();

	_set myset;
	_set::value_compare mycomp = myset.value_comp();
	for (int i=0; i<=5; i++) myset.insert(i);
	int highest = *(myset.rbegin());
	_set::iterator it=myset.begin();
	do {
		V.push_back(*it);
	}
	while ( mycomp(*(++it),highest) );

	res.std_end = timer();
}


static void find_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	for (int i = 1; i < 100; i++)
		m.insert(i);
	V.push_back(*m.find(10));
	V.push_back(*m.find(42));
	_set::const_iterator it = m.find(9);
	V.push_back(*it);

	res.ft_end = timer();
}

static void find_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;
	(void) V;

	res.std_start = timer();

	_set m;
	for (int i = 1; i < 100; i++)
		m.insert(i);
	V.push_back(*m.find(10));
	V.push_back(*m.find(42));
	_set::const_iterator it = m.find(9);
	V.push_back(*it);

	res.std_end = timer();
}

static void count_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	V.push_back(m.count(10));
	for (int i = 1; i < 100; i++)
		m.insert(i);

	V.push_back(m.count(10));
	V.push_back(m.count(42));
	V.push_back(m.count(99999));

	res.ft_end = timer();
}

static void count_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;
	(void) V;

	res.std_start = timer();

	_set m;
	V.push_back(m.count(10));
	for (int i = 1; i < 100; i++)
		m.insert(i);

	V.push_back(m.count(10));
	V.push_back(m.count(42));
	V.push_back(m.count(99999));

	res.std_end = timer();
}


static void lower_bound_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	for (int i = 1; i < 100; i += 10)
		m.insert(i);
	V.push_back(*m.lower_bound(1));
	V.push_back(*m.lower_bound(15));
	V.push_back(*m.lower_bound(11));
	V.push_back(*m.lower_bound(10));
	V.push_back( m.lower_bound(99) == m.end() );
	V.push_back( m.lower_bound(9999) == m.end() );
	V.push_back( m.lower_bound(9991) == m.end() );

	_set mp2;

	mp2.insert(20);
	mp2.insert(30);
	mp2.insert(40);
	mp2.insert(50);
	mp2.insert(60);
	_set::iterator it;
	for (int i = 11; i < 70; i += 10) {
		it = mp2.lower_bound(i);
		if (it != mp2.end())
			V.push_back(*it);
	}


	res.ft_end = timer();
}

static void lower_bound_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m;
	for (int i = 1; i < 100; i += 10)
		m.insert(i);
	V.push_back(*m.lower_bound(1));
	V.push_back(*m.lower_bound(15));
	V.push_back(*m.lower_bound(11));
	V.push_back(*m.lower_bound(10));
	V.push_back( m.lower_bound(99) == m.end() );
	V.push_back( m.lower_bound(9999) == m.end() );
	V.push_back( m.lower_bound(9991) == m.end() );

	_set mp2;

	mp2.insert(20);
	mp2.insert(30);
	mp2.insert(40);
	mp2.insert(50);
	mp2.insert(60);
	_set::iterator it;
	for (int i = 11; i < 70; i += 10) {
		it = mp2.lower_bound(i);
		if (it != mp2.end())
			V.push_back(*it);
	}

	res.std_end = timer();
}

static void upper_bound_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m;
	for (int i = 1; i < 10000; i += 10)
		m.insert(i);
	V.push_back(*m.upper_bound(1));
	V.push_back(*m.upper_bound(15));
	V.push_back(*m.upper_bound(11));
	V.push_back(*m.upper_bound(10));
	V.push_back(m.upper_bound(9999) == m.end());
	V.push_back(m.upper_bound(9991) == m.end());

	res.ft_end = timer();
}

static void upper_bound_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;
	(void) V;

	res.std_start = timer();

	_set m;
	for (int i = 1; i < 10000; i += 10)
		m.insert(i);
	V.push_back(*m.upper_bound(1));
	V.push_back(*m.upper_bound(15));
	V.push_back(*m.upper_bound(11));
	V.push_back(*m.upper_bound(10));
	V.push_back(m.upper_bound(9999) == m.end());
	V.push_back(m.upper_bound(9991) == m.end());

	res.std_end = timer();
}


static void equal_range_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m2;
	V.push_back(m2.equal_range(200).first == m2.end());
	V.push_back(m2.equal_range(200).first == m2.end());

	m2.insert(7);
	m2.insert(3);
	m2.insert(2);
	m2.insert(4);
	m2.insert(6);
	m2.insert(11);
	m2.insert(9);
	m2.insert(18);
	m2.insert(14);
	m2.insert(12);
	m2.insert(17);
	m2.insert(22);
	m2.insert(19);
	m2.insert(20);

	V.push_back (*(m2.equal_range(18).first));
	V.push_back (*(m2.equal_range(18).second));
	V.push_back (*(m2.equal_range(16).first));
	V.push_back (*(m2.equal_range(16).second));
	V.push_back (*(m2.equal_range(20).first));
	V.push_back (*(m2.equal_range(20).second));
	V.push_back ((m2.equal_range(200).first) == m2.end());
	V.push_back ((m2.equal_range(200).second == m2.end()));

	res.ft_end = timer();
}

static void equal_range_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;
	(void) V;

	res.std_start = timer();

	_set m2;
	V.push_back(m2.equal_range(200).first == m2.end());
	V.push_back(m2.equal_range(200).first == m2.end());

	m2.insert(7);
	m2.insert(3);
	m2.insert(2);
	m2.insert(4);
	m2.insert(6);
	m2.insert(11);
	m2.insert(9);
	m2.insert(18);
	m2.insert(14);
	m2.insert(12);
	m2.insert(17);
	m2.insert(22);
	m2.insert(19);
	m2.insert(20);

	V.push_back (*(m2.equal_range(18).first));
	V.push_back (*(m2.equal_range(18).second));
	V.push_back (*(m2.equal_range(16).first));
	V.push_back (*(m2.equal_range(16).second));
	V.push_back (*(m2.equal_range(20).first));
	V.push_back (*(m2.equal_range(20).second));
	V.push_back ((m2.equal_range(200).first) == m2.end());
	V.push_back ((m2.equal_range(200).second == m2.end()));

	res.std_end = timer();
}

static void get_allocator_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set myset;

	int * p;
	unsigned int i;

	// allocate an array of 5 elements using myset's allocator:
	p=myset.get_allocator().allocate(5);

	// assign some values to array
	for (i=0; i<5; i++) p[i]=(i+1)*10;
	for (i=0; i<5; i++) V.push_back(p[i]);
	myset.get_allocator().deallocate(p,5);

	res.ft_end = timer();
}

static void get_allocator_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;
	(void) V;

	res.std_start = timer();

	_set myset;

	int * p;
	unsigned int i;

	// allocate an array of 5 elements using myset's allocator:
	p=myset.get_allocator().allocate(5);

	// assign some values to array
	for (i=0; i<5; i++) p[i]=(i+1)*10;
	for (i=0; i<5; i++) V.push_back(p[i]);
	myset.get_allocator().deallocate(p,5);

	res.std_end = timer();
}


static void relational_operators_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	_set m2;
	_set m;
	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);
	m2.insert(7);
	m2.insert(3);
	m2.insert(2);
	m2.insert(4);
	m2.insert(6);
	m2.insert(11);
	m2.insert(9);
	m2.insert(18);
	m2.insert(14);
	m2.insert(12);
	m2.insert(17);
	m2.insert(22);
	m2.insert(19);
	m2.insert(20);

	m.insert(7);
	m.insert(3);
	m.insert(2);
	m.insert(4);
	m.insert(6);
	m.insert(11);
	m.insert(9);
	m.insert(18);
	m.insert(14);
	m.insert(12);
	m.insert(17);
	m.insert(22);
	m.insert(19);
	m.insert(20);

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);


	m.insert(100000000);

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);

	res.ft_end = timer();
}

static void relational_operators_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;

	res.std_start = timer();

	_set m2;
	_set m;
	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);
	m2.insert(7);
	m2.insert(3);
	m2.insert(2);
	m2.insert(4);
	m2.insert(6);
	m2.insert(11);
	m2.insert(9);
	m2.insert(18);
	m2.insert(14);
	m2.insert(12);
	m2.insert(17);
	m2.insert(22);
	m2.insert(19);
	m2.insert(20);

	m.insert(7);
	m.insert(3);
	m.insert(2);
	m.insert(4);
	m.insert(6);
	m.insert(11);
	m.insert(9);
	m.insert(18);
	m.insert(14);
	m.insert(12);
	m.insert(17);
	m.insert(22);
	m.insert(19);
	m.insert(20);

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);


	m.insert(100000000);

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);

	res.std_end = timer();
}


static void swap_overload_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::set<int> _set;

	res.ft_start = timer();

	int myints[]={12,75,10,32,20,25};
	_set first (myints,myints+3);     // 10,12,75
	_set second (myints+3,myints+6);  // 20,25,32
	swap(first,second);
	for (_set::iterator it=first.begin(); it!=first.end(); ++it)
		V.push_back(*it);
	for (_set::iterator it=second.begin(); it!=second.end(); ++it)
		V.push_back(*it);

	res.ft_end = timer();
}

static void swap_overload_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::set<int> _set;
	(void) V;

	res.std_start = timer();

	int myints[]={12,75,10,32,20,25};
	_set first (myints,myints+3);     // 10,12,75
	_set second (myints+3,myints+6);  // 20,25,32
	swap(first,second);
	for (_set::iterator it=first.begin(); it!=first.end(); ++it)
		V.push_back(*it);
	for (_set::iterator it=second.begin(); it!=second.end(); ++it)
		V.push_back(*it);

	res.std_end = timer();
}



//----------------------------------------------------
void set_test(void)
{
	std::vector<int>	s;
	std::vector<int>	u;
	struct s_time_res	t_res;

	std::cout << "********************************************************************" << std::endl;
	std::cout << "->                              SET                               <-" << std::endl;
	std::cout << "********************************************************************" << std::endl;

	print_header();

	construct_test_u(u, t_res);
	construct_test_s(s, t_res);
	print_res("Constructors", s, u, t_res);
	u.clear();
	s.clear();

	begin_test_u(u, t_res);
	begin_test_s(s, t_res);
	print_res("Begin", s, u, t_res);
	u.clear();
	s.clear();

	end_test_u(u, t_res);
	end_test_s(s, t_res);
	print_res("end", s, u, t_res);
	u.clear();
	s.clear();

	rbegin_test_u(u, t_res);
	rbegin_test_s(s, t_res);
	print_res("rbegin", s, u, t_res);
	u.clear();
	s.clear();

	rend_test_u(u, t_res);
	rend_test_s(s, t_res);
	print_res("rend", s, u, t_res);
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

	insert_test_u(u, t_res);
	insert_test_s(s, t_res);
	print_res("insert", s, u, t_res);
	u.clear();
	s.clear();

	erase_test_u(u, t_res);
	erase_test_s(s, t_res);
	print_res("erase", s, u, t_res);
	u.clear();
	s.clear();

	swap_test_u(u, t_res);
	swap_test_s(s, t_res);
	print_res("swap", s, u, t_res);
	u.clear();
	s.clear();

	clear_test_u(u, t_res);
	clear_test_s(s, t_res);
	print_res("clear", s, u, t_res);
	u.clear();
	s.clear();

	key_comp_test_u(u, t_res);
	key_comp_test_s(s, t_res);
	print_res("key_comp", s, u, t_res);
	u.clear();
	s.clear();

	value_comp_test_u(u, t_res);
	value_comp_test_s(s, t_res);
	print_res("value_comp", s, u, t_res);
	u.clear();
	s.clear();

	find_test_u(u, t_res);
	find_test_s(s, t_res);
	print_res("find", s, u, t_res);
	u.clear();
	s.clear();

	count_test_u(u, t_res);
	count_test_s(s, t_res);
	print_res("count", s, u, t_res);
	u.clear();
	s.clear();


	lower_bound_test_u(u, t_res);
	lower_bound_test_s(s, t_res);
	print_res("lower_bound", s, u, t_res);
	u.clear();
	s.clear();

	upper_bound_test_u(u, t_res);
	upper_bound_test_s(s, t_res);
	print_res("upper_bound", s, u, t_res);
	u.clear();
	s.clear();

	equal_range_test_u(u, t_res);
	equal_range_test_s(s, t_res);
	print_res("equal_range", s, u, t_res);
	u.clear();
	s.clear();

	get_allocator_test_u(u, t_res);
	get_allocator_test_s(s, t_res);
	print_res("get_allocator", s, u, t_res);
	u.clear();
	s.clear();

	relational_operators_test_u(u, t_res);
	relational_operators_test_s(s, t_res);
	print_res("relational_operators", s, u, t_res);
	u.clear();
	s.clear();

	swap_overload_test_u(u, t_res);
	swap_overload_test_s(s, t_res);
	print_res("swap_overload", s, u, t_res);
	u.clear();
	s.clear();
}