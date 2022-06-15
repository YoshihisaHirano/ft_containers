#include <unistd.h>
#include <sys/time.h>
#include <stack>
#include <map>
#include <vector>
#include <iomanip>
#include <iterator>
#include "../utility.hpp"
#include "../map.hpp"

static void construct_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();
	_map m;
	m[5] = 10;
	for (int i = 0; i < 20; i++)
		m[i] = i * 10;

	V.push_back(m[10]);
	V.push_back(m[11]);
	V.push_back(m[15]);
	V.push_back(m.size());
	_map m2(m.begin(), m.end());
	V.push_back(m[10]);
	V.push_back(m[11]);
	V.push_back(m[15]);
	V.push_back(m.size());

	_map m3(m2);
	V.push_back(m3[10]);
	V.push_back(m3[11]);
	V.push_back(m3[15]);
	V.push_back(m3.size());
	V.push_back(m3 == m2);
	V.push_back(m3 != m2);
	V.push_back(m3 <= m2);
	V.push_back(m3 < m2);
	V.push_back(m3 > m2);
	V.push_back(m3 >= m2);



	res.ft_end = timer();
}

static void construct_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;
	m[5] = 10;
	for (int i = 0; i < 20; i++)
		m[i] = i * 10;

	V.push_back(m[10]);
	V.push_back(m[11]);
	V.push_back(m[15]);
	V.push_back(m.size());
	_map m2(m.begin(), m.end());
	V.push_back(m[10]);
	V.push_back(m[11]);
	V.push_back(m[15]);
	V.push_back(m.size());

	_map m3(m2);
	V.push_back(m3[10]);
	V.push_back(m3[11]);
	V.push_back(m3[15]);
	V.push_back(m3.size());
	V.push_back(m3 == m2);
	V.push_back(m3 != m2);
	V.push_back(m3 <= m2);
	V.push_back(m3 < m2);
	V.push_back(m3 > m2);
	V.push_back(m3 >= m2);
	res.std_end = timer();
}

static void insert_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	_map m;
	for (int i = 0; i < 10000; i++)
		m[i] = i;
	V.push_back(m[10]);
	V.push_back(m[11]);
	V.push_back(m[1100]);
	V.push_back(m[15]);
	V.push_back(m.size());

	res.ft_end = timer();
}

static void insert_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;
	for (int i = 0; i < 10000; i++)
		m[i] = i;
	V.push_back(m[10]);
	V.push_back(m[11]);
	V.push_back(m[1100]);
	V.push_back(m[15]);
	V.push_back(m.size());

	res.std_end = timer();
}

static void empty_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	_map m;
	V.push_back(m.empty());

	for (int i = 0; i < 10; i++)
		m[i] = i;
	V.push_back(m[5]);
	V.push_back(m.empty());

	res.ft_end = timer();
}

static void empty_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;
	V.push_back(m.empty());
	for (int i = 0; i < 10; i++)
		m[i] = i;
	V.push_back(m[5]);
	V.push_back(m.empty());

	res.std_end = timer();
}


static void begin_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();


	_map m;

	V.push_back(m.empty());
	for (int i = 1; i < 1000; i++)
		m[i] = i * 100;
	V.push_back(m[50]);
	V.push_back(m.empty());
	V.push_back(m.size());
	_map::iterator it = m.begin();
	V.push_back((*it).first);
	V.push_back(it->second);
	++it;
	V.push_back((*it).first);
	V.push_back(it->second);
	_map::iterator it2 = m.begin();
	V.push_back(it == it2);
	_map::iterator it3 = it;
	V.push_back(it == it3);
	it++;
	V.push_back(it->second);
	--it;

	V.push_back(it->second);
	it--;
	V.push_back(it->second);

	res.ft_end = timer();
}

static void begin_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;

	V.push_back(m.empty());
	for (int i = 1; i < 1000; i++)
		m[i] = i * 100;
	V.push_back(m[50]);
	V.push_back(m.empty());
	V.push_back(m.size());
	_map::iterator it = m.begin();
	V.push_back((*it).first);
	V.push_back(it->second);
	++it;
	V.push_back((*it).first);
	V.push_back(it->second);
	_map::iterator it2 = m.begin();
	V.push_back(it == it2);
	_map::iterator it3 = it;
	V.push_back(it == it3);
	it++;
	V.push_back(it->second);
	--it;
	V.push_back(it->second);
	it--;
	V.push_back(it->second);

	res.std_end = timer();
}


static void end_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();


	_map m;

	V.push_back(m.empty());
	for (int i = 1; i < 10000; i++)
		m[i] = i * 100;
	V.push_back(m[50]);
	V.push_back(m.empty());
	V.push_back(m.size());
	_map::iterator ite = m.end();
	ite--;
	V.push_back(ite->first);
	V.push_back(ite->second);
	--ite;
	V.push_back(ite->first);
	V.push_back(ite->second);

	_map m2;
	m2[5] = 5;
	for (int i = 1; i < 10; i++)
		m2[i] = i;
	_map::iterator it = m2.begin();

	ite = m2.end();
	ite--;
	for (; it != ite; ite--)
		V.push_back(ite->first);

	res.ft_end = timer();
}

static void end_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;
	V.push_back(m.empty());
	for (int i = 1; i < 10000; i++)
		m[i] = i * 100;
	V.push_back(m[50]);
	V.push_back(m.empty());
	V.push_back(m.size());
	_map::iterator ite = m.end();
	ite--;
	V.push_back(ite->first);
	V.push_back(ite->second);
	--ite;
	V.push_back(ite->first);
	V.push_back(ite->second);

	_map m2;
	m2[5] = 5;
	for (int i = 1; i < 10; i++)
		m2[i] = i;
	_map::iterator it = m2.begin();

	ite = m2.end();
	ite--;
	for (; it != ite; ite--)
		V.push_back(ite->first);

	res.std_end = timer();
}


static void rbegin_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();


	_map m;

	V.push_back(m.empty());
	m[5] = 5;
	for (int i = 1; i < 100; i++)
		m[i] = i * 100;
	_map::reverse_iterator it = m.rbegin();
	_map::reverse_iterator ite = m.rend();

	for (; it != ite; it++)
		V.push_back(it->first);



	res.ft_end = timer();
}

static void rbegin_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;

	V.push_back(m.empty());
	m[5] = 5;
	for (int i = 1; i < 100; i++)
		m[i] = i * 100;
	_map::reverse_iterator it = m.rbegin();
	_map::reverse_iterator ite = m.rend();
	for (; it != ite; it++)
		V.push_back(it->first);
	res.std_end = timer();
}



// static void maxsize_test_u(std::vector<int> &V, struct s_time_res &res)
// {
// 	typedef ft::map<int, int> _map;

// 	res.ft_start = timer();

// 	_map m;

// 	V.push_back(m.empty());
// 	V.push_back(m.max_size());
// 	std::cout << m.max_size() << " ft "  << std::endl;
// 	m[5] = 5;
// 	for (int i = 1; i < 100; i++)
// 		m[i] = i * 100;
// 	std::cout << m.max_size() << " ft "  << std::endl;
// 	V.push_back(m.max_size());

// 	res.ft_end = timer();
// }


// static void maxsize_test_s(std::vector<int> &V, struct s_time_res &res)
// {
// 	typedef std::map<int, int> _map;

// 	res.std_start = timer();

// 	_map m;

// 	V.push_back(m.empty());
// 	V.push_back(m.max_size());
// 	std::cout << m.max_size() << " std " << std::endl;
// 	m[5] = 5;
// 	for (int i = 1; i < 100; i++)
// 		m[i] = i * 100;
// 	std::cout << m.max_size() << " std " << std::endl;
// 	V.push_back(m.max_size());

// 	res.std_end = timer();
// }


static void insert_insert_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();


	_map m;
	V.push_back(m.empty());
	for (int i = 0; i < 1000; i++)
		m.insert(ft::make_pair(i, i * 100));

	V.push_back(m.insert(ft::make_pair(100, 100)).second);
	V.push_back(m.insert(ft::make_pair(1000000, 100000)).second);
	V.push_back(m[99]);

	_map m2;
	m2.insert(m.begin(), m.end());
	V.push_back(m2.size());
	V.push_back(m2[19]);
	V.push_back(m2[99]);
	V.push_back(m2[999]);

	_map m3;
	m3[7] = 7;
	m3[3] = 3;
	m3[2] = 2;
	m3[4] = 4;
	m3[6] = 6;
	m3[11] = 11;
	m3[9] = 9;
	m3[18] = 18;
	m3[14] = 14;
	m3[12] = 12;
	m3[17] = 17;
	m3[22] = 22;
	m3[19] = 19;
	m3[20] = 20;

	_map::iterator it = m3.find(12);

	m3.insert(it, ft::make_pair(13,13));

	res.ft_end = timer();
}

static void insert_insert_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;
	V.push_back(m.empty());
	for (int i = 0; i < 1000; i++)
	{
		m.insert(std::make_pair(i, i * 100));
	}
	// m.insert(std::make_pair(i, i * 100));

	V.push_back(m.insert(std::make_pair(100, 100)).second);
	V.push_back(m.insert(std::make_pair(1000000, 100000)).second);
	V.push_back(m[99]);
	_map m2;


	m2.insert(m.begin(), m.end());
	V.push_back(m2.size());
	V.push_back(m2[19]);
	V.push_back(m2[99]);
	V.push_back(m2[999]);


	res.std_end = timer();
}


static void erase_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();


	_map m;
	V.push_back(m.empty());
	for (int i = 1; i < 10; i++)
		m.insert(ft::make_pair(i, i * 100));

	m.erase( (m.begin()) ); // ok
	V.push_back(m.size());
	_map::iterator it = m.begin();
	it++;
	it++;
	m.erase( it ); // ?
	V.push_back(m.size());
	it = m.begin();
	for (; it != m.end(); it++)
		V.push_back(it->first);
	m.erase(6);
	m.erase(7);
	for (; it != m.end(); it++)
		V.push_back(it->first);

	it = m.begin();
	it++;
	it++;
	it++;
	m.erase(m.begin(), it);

	for (; it != m.end(); it++)
		V.push_back(it->first);
	V.push_back(m.size());

	_map m2;
	m2[7] = 7;
	m2[11] = 11;
	m2[9] = 9;
	m2[18] = 18;
	m2[14] = 14;
	m2[22] = 22;
	m2[19] = 19;
	m2[20] = 20;
	it = m2.begin();
	m2.erase(7);
	it = m2.begin();
	for (; it != m2.end(); it++)
		V.push_back(it->first);

	res.ft_end = timer();
}

static void erase_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;
	V.push_back(m.empty());
	m[5] = 5;
	for (int i = 1; i < 10; i++)
		m.insert(std::make_pair(i, i * 100));

	m.erase( (m.begin()) );
	V.push_back(m.size());
	_map::iterator it = m.begin();
	it++;
	it++;
	m.erase( it );
	V.push_back(m.size());
	it = m.begin();
	for (; it != m.end(); it++)
		V.push_back(it->first);
	m.erase(6);
	m.erase(7);
	for (; it != m.end(); it++)
		V.push_back(it->first);

	it = m.begin();
	it++;
	it++;
	it++;
	m.erase(m.begin(), it);
	for (; it != m.end(); it++)
		V.push_back(it->first);
	V.push_back(m.size());

	_map m2;
	m2[7] = 7;
	m2[11] = 11;
	m2[9] = 9;
	m2[18] = 18;
	m2[14] = 14;
	m2[22] = 22;
	m2[19] = 19;
	m2[20] = 20;
	it = m2.begin();
	m2.erase(7);
	it = m2.begin();
	for (; it != m2.end(); it++)
		V.push_back(it->first);
	res.std_end = timer();
}

static void clear_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();


	_map m;
	V.push_back(m.empty());
	m[5] = 5;
	for (int i = 1; i < 10; i++)
		m.insert(ft::make_pair(i, i * 100));
	m.clear();
	V.push_back(m.size());

	res.ft_end = timer();
}

static void clear_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;
	V.push_back(m.empty());
	m[5] = 5;
	for (int i = 1; i < 10; i++)
		m.insert(std::make_pair(i, i * 100));
	m.clear();
	V.push_back(m.size());

	res.std_end = timer();
}

static void swap_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	(void) V;
	_map m;
	_map m2;
	for (int i = 1; i < 10; i++)
		m.insert(ft::make_pair(i, i * 100));

	for (int i = 1; i < 10; i++)
		m2.insert(ft::make_pair(i, i));
	m.swap(m2);
	V.push_back(m.size());
	V.push_back(m2.size());
	_map::iterator it = m.begin();
	for (; it != m.end(); it++)
		V.push_back(it->second);
	it = m2.begin();
	for (; it != m2.end(); it++)
		V.push_back(it->second);

	res.ft_end = timer();
}

static void swap_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;
	(void) V;

	res.std_start = timer();

	_map m;
	_map m2;
	for (int i = 1; i < 10; i++)
		m.insert(std::make_pair(i, i * 100));

	for (int i = 1; i < 10; i++)
		m2.insert(std::make_pair(i, i));
	m.swap(m2);
	V.push_back(m.size());
	V.push_back(m2.size());
	_map::iterator it = m.begin();
	for (; it != m.end(); it++)
		V.push_back(it->second);
	it = m2.begin();
	for (; it != m2.end(); it++)
		V.push_back(it->second);

	res.std_end = timer();
}

static void find_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	(void) V;
	_map m;
	for (int i = 1; i < 100; i++)
		m.insert(ft::make_pair(i, i * 100));

	V.push_back(m.find(10)->second);
	V.push_back(m.find(42)->second);

	_map::const_iterator it = m.find(9);
	V.push_back(it->second);

	res.ft_end = timer();
}

static void find_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;
	(void) V;

	res.std_start = timer();

	_map m;
	for (int i = 1; i < 100; i++)
		m.insert(std::make_pair(i, i * 100));

	V.push_back(m.find(10)->second);
	V.push_back(m.find(42)->second);

	_map::const_iterator it = m.find(9);
	V.push_back(it->second);

	res.std_end = timer();
}

static void count_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	(void) V;
	_map m;
	V.push_back(m.count(10));
	for (int i = 1; i < 100; i++)
		m.insert(ft::make_pair(i, i * 100));

	V.push_back(m.count(10));
	V.push_back(m.count(42));
	V.push_back(m.count(99999));

	res.ft_end = timer();
}

static void count_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;
	(void) V;

	res.std_start = timer();

	_map m;
	V.push_back(m.count(10));
	for (int i = 1; i < 100; i++)
		m.insert(std::make_pair(i, i * 100));

	V.push_back(m.count(10));
	V.push_back(m.count(42));
	V.push_back(m.count(99999));

	res.std_end = timer();
}


static void lower_bound_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	_map m;
	for (int i = 1; i < 100; i += 10)
		m.insert(ft::make_pair(i, i * 100));
	V.push_back(m.lower_bound(1)->first);
	V.push_back(m.lower_bound(15)->first);
	V.push_back(m.lower_bound(11)->first);
	V.push_back(m.lower_bound(10)->first);
	V.push_back( m.lower_bound(99) == m.end() );
	V.push_back( m.lower_bound(9999) == m.end() );
	V.push_back( m.lower_bound(9991) == m.end() );

	_map mp2;

	mp2.insert(ft::make_pair(20, 20));
	mp2.insert(ft::make_pair(30, 30));
	mp2.insert(ft::make_pair(40, 40));
	mp2.insert(ft::make_pair(50, 50));
	mp2.insert(ft::make_pair(60, 60));
	_map::iterator it;
	for (int i = 11; i < 70; i += 10) {
		it = mp2.lower_bound(i);
		if (it != mp2.end())
			V.push_back(it->first);
	}


	res.ft_end = timer();
}

static void lower_bound_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m;
	for (int i = 1; i < 100; i += 10)
		m.insert(std::make_pair(i, i * 100));
	V.push_back(m.lower_bound(1)->first);
	V.push_back(m.lower_bound(15)->first);
	V.push_back(m.lower_bound(11)->first);
	V.push_back(m.lower_bound(10)->first);
	V.push_back( m.lower_bound(99) == m.end() );
	V.push_back( m.lower_bound(9999) == m.end() );
	V.push_back( m.lower_bound(9991) == m.end() );

	_map mp2;

	mp2.insert(std::make_pair(20, 20));
	mp2.insert(std::make_pair(30, 30));
	mp2.insert(std::make_pair(40, 40));
	mp2.insert(std::make_pair(50, 50));
	mp2.insert(std::make_pair(60, 60));
	_map::iterator it;
	for (int i = 11; i < 70; i += 10) {
		it = mp2.lower_bound(i);
		if (it != mp2.end())
			V.push_back(it->first);
	}

	res.std_end = timer();
}

static void upper_bound_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	(void) V;
	_map m;
	for (int i = 1; i < 10000; i += 10)
		m.insert(ft::make_pair(i, i * 100));
	V.push_back(m.upper_bound(1)->first);
	V.push_back(m.upper_bound(15)->first);
	V.push_back(m.upper_bound(11)->first);
	V.push_back(m.upper_bound(10)->first);
	V.push_back(m.upper_bound(9999) == m.end());
	V.push_back(m.upper_bound(9991) == m.end());

	res.ft_end = timer();
}

static void upper_bound_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;
	(void) V;

	res.std_start = timer();

	_map m;
	for (int i = 1; i < 10000; i += 10)
		m.insert(std::make_pair(i, i * 100));
	V.push_back(m.upper_bound(1)->first);
	V.push_back(m.upper_bound(15)->first);
	V.push_back(m.upper_bound(11)->first);
	V.push_back(m.upper_bound(10)->first);
	V.push_back(m.upper_bound(9999) == m.end());
	V.push_back(m.upper_bound(9991) == m.end());

	res.std_end = timer();
}


static void equal_range_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	_map m2;
	V.push_back(m2.equal_range(200).first == m2.end());
	V.push_back(m2.equal_range(200).second == m2.end());
	m2[7] = 7;
	m2[3] = 3;
	m2[2] = 2;
	m2[4] = 4;
	m2[6] = 6;
	m2[11] = 11;
	m2[9] = 9;
	m2[18] = 18;
	m2[14] = 14;
	m2[12] = 12;
	m2[17] = 17;
	m2[22] = 22;
	m2[19] = 19;
	m2[20] = 20;

	V.push_back(m2.equal_range(18).first->first);
	V.push_back(m2.equal_range(18).second->first);

	V.push_back(m2.equal_range(16).first->first);
	V.push_back(m2.equal_range(16).second->first);
	V.push_back(m2.equal_range(20).first->first);
	V.push_back(m2.equal_range(20).second->first);
	V.push_back(m2.equal_range(200).first == m2.end());
	V.push_back(m2.equal_range(200).second == m2.end());



	res.ft_end = timer();
}

static void equal_range_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;
	(void) V;

	res.std_start = timer();

	_map m2;
	V.push_back(m2.equal_range(200).first == m2.end());
	V.push_back(m2.equal_range(200).second == m2.end());
	m2[7] = 7;
	m2[3] = 3;
	m2[2] = 2;
	m2[4] = 4;
	m2[6] = 6;
	m2[11] = 11;
	m2[9] = 9;
	m2[18] = 18;
	m2[14] = 14;
	m2[12] = 12;
	m2[17] = 17;
	m2[22] = 22;
	m2[19] = 19;
	m2[20] = 20;

	V.push_back(m2.equal_range(18).first->first);
	V.push_back(m2.equal_range(18).second->first);

	V.push_back(m2.equal_range(16).first->first);
	V.push_back(m2.equal_range(16).second->first);
	V.push_back(m2.equal_range(20).first->first);
	V.push_back(m2.equal_range(20).second->first);
	V.push_back(m2.equal_range(200).first == m2.end());
	V.push_back(m2.equal_range(200).second == m2.end());

	res.std_end = timer();
}


static void relational_operators_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;

	res.ft_start = timer();

	_map m2;
	_map m;
	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);
	m2[7] = 7;
	m2[3] = 3;
	m2[2] = 2;
	m2[4] = 4;
	m2[6] = 6;
	m2[11] = 11;
	m2[9] = 9;
	m2[18] = 18;
	m2[14] = 14;
	m2[12] = 12;
	m2[17] = 17;
	m2[22] = 22;
	m2[19] = 19;
	m2[20] = 20;

	m[7] = 7;
	m[3] = 3;
	m[2] = 2;
	m[4] = 4;
	m[6] = 6;
	m[11] = 11;
	m[9] = 9;
	m[18] = 18;
	m[14] = 14;
	m[12] = 12;
	m[17] = 17;
	m[22] = 22;
	m[19] = 19;
	m[20] = 20;

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);


	m[100] = 100000;

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
	typedef std::map<int, int> _map;

	res.std_start = timer();

	_map m2;
	_map m;

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);
	m2[7] = 7;
	m2[3] = 3;
	m2[2] = 2;
	m2[4] = 4;
	m2[6] = 6;
	m2[11] = 11;
	m2[9] = 9;
	m2[18] = 18;
	m2[14] = 14;
	m2[12] = 12;
	m2[17] = 17;
	m2[22] = 22;
	m2[19] = 19;
	m2[20] = 20;

	m[7] = 7;
	m[3] = 3;
	m[2] = 2;
	m[4] = 4;
	m[6] = 6;
	m[11] = 11;
	m[9] = 9;
	m[18] = 18;
	m[14] = 14;
	m[12] = 12;
	m[17] = 17;
	m[22] = 22;
	m[19] = 19;
	m[20] = 20;

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);


	m[100] = 100000;

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);

	res.std_end = timer();
}

static void assignment_overload_test_u(std::vector<int> &V, struct s_time_res &res)
{
	typedef ft::map<int, int> _map;
	(void) V;

	res.ft_start = timer();

	_map m2;
	_map m;


	m2[7] = 7;
	m2[3] = 3;
	m2[2] = 2;
	m2[4] = 4;
	m2[6] = 6;
	m2[11] = 11;
	m2[9] = 9;
	m2[18] = 18;
	m2[14] = 14;
	m2[12] = 12;
	m2[17] = 17;
	m2[22] = 22;
	m2[19] = 19;
	m2[20] = 20;

	// m2.begin()->first = 99;

	m = m2;

	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);

	res.ft_end = timer();
}


static void assignment_overload_test_s(std::vector<int> &V, struct s_time_res &res)
{
	typedef std::map<int, int> _map;
	(void) V;

	res.std_start = timer();

	_map m2;
	_map m;


	m2[7] = 7;
	m2[3] = 3;
	m2[2] = 2;
	m2[4] = 4;
	m2[6] = 6;
	m2[11] = 11;
	m2[9] = 9;
	m2[18] = 18;
	m2[14] = 14;
	m2[12] = 12;
	m2[17] = 17;
	m2[22] = 22;
	m2[19] = 19;
	m2[20] = 20;

	m = m2;


	V.push_back(m2 == m);
	V.push_back(m2 != m);
	V.push_back(m2 < m);
	V.push_back(m2 <= m);
	V.push_back(m2 > m);
	V.push_back(m2 >= m);



	res.std_end = timer();
}


//----------------------------------------------------
void map_test(void)
{
	std::vector<int>	s;
	std::vector<int>	u;
	struct s_time_res	t_res;

	std::cout << "********************************************************************" << std::endl;
	std::cout << "->                              MAP                               <-" << std::endl;
	std::cout << "********************************************************************" << std::endl;

	print_header();

	construct_test_u(u, t_res);
	construct_test_s(s, t_res);
	print_res("Constructors", s, u, t_res);
	u.clear();
	s.clear();


	insert_test_u(u, t_res);
	insert_test_s(s, t_res);
	print_res("Operator[]", s, u, t_res);
	u.clear();
	s.clear();

	empty_test_u(u, t_res);
	empty_test_s(s, t_res);
	print_res("Empty", s, u, t_res);
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

	// maxsize_test_u(u, t_res);
	// maxsize_test_s(s, t_res);
	// print_res("maxsize", s, u, t_res);
	// u.clear();
	// s.clear();

	insert_insert_test_u(u, t_res);
	insert_insert_test_s(s, t_res);
	print_res("insert", s, u, t_res);
	u.clear();
	s.clear();

	erase_test_u(u, t_res);
	erase_test_s(s, t_res);
	print_res("erase", s, u, t_res);
	u.clear();
	s.clear();

	clear_test_u(u, t_res);
	clear_test_s(s, t_res);
	print_res("clear", s, u, t_res);
	u.clear();
	s.clear();

	swap_test_u(u, t_res);
	swap_test_s(s, t_res);
	print_res("swap", s, u, t_res);
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

	relational_operators_test_u(u, t_res);
	relational_operators_test_s(s, t_res);
	print_res("relational_operators", s, u, t_res);
	u.clear();
	s.clear();

	assignment_overload_test_u(u, t_res);
	assignment_overload_test_s(s, t_res);
	print_res("assignment_overload", s, u, t_res);
	u.clear();
	s.clear();


}