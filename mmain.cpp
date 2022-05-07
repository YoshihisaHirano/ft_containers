#include "map.hpp"
#include <iostream>
#include <map>
int main()
{
//	{
//	ft::map<int, char> mymap;
//	mymap.begin();
//	mymap.end();
//	std::cout << "mymap is empty: " << mymap.empty() << std::endl;
//	mymap.insert(ft::pair<int, int>(4, 'a'));
//	mymap.insert(ft::pair<int, int>(7, 'b'));
//	std::cout << "starting a for loop " << std::endl;
//	for (int i = 0; i < 10; i++)
//		mymap.insert(ft::pair<int, char>(i, i + 35));
//	mymap[11] = 'v';
//	std::cout << "mymap size: " << mymap.size() << std::endl;
//	ft::map<int, char>::iterator it = mymap.begin();
//	it++;
//	std::cout << "mymap begin + 1: " << (*it).first << " " << (*it).second << std::endl;
//	ft::map<int, char>::iterator ite = mymap.end();
//	ite--;
//	std::cout << "mymap end - 1: " << (*ite).first << " " << (*ite).second << std::endl;
//	ite--;
//	std::cout << "mymap end - 2: " << (*ite).first << " " << (*ite).second << std::endl;
//	ite--;
//	std::cout << "mymap end - 3: " << (*ite).first << " " << (*ite).second << std::endl;
//	ft::map<int, char>::reverse_iterator rit = mymap.rend();
//	rit--;
//	std::cout << "mymap rend - 1: " << (*rit).first << " " << (*rit).second << std::endl;
//	ft::map<int, char>::reverse_iterator rite = mymap.rbegin();
//	// rite++;
//	std::cout << "mymap rbegin + 1: " << (*rite).first << " " << (*rite).second << std::endl;
//	std::cout << "mymap count 11: " << mymap.count(11) << std::endl;
//	std::cout << "mymap count 12: " << mymap.count(12) << std::endl;
//
//	ft::map<int,char> anothermap;
//	anothermap.insert(mymap.begin(),mymap.find(8));
//
//  // showing contents:
//	std::cout << "mymap contains:\n";
//	for (it=mymap.begin(); it!=mymap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//	std::cout << "anothermap contains:\n";
//	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//	ft::map<char,int> mymap1;
//	ft::map<char,int>::iterator itlow,itup;
//	mymap1['a']=20;
//	mymap1['b']=40;
//	mymap1['c']=60;
//	mymap1['d']=80;
//	mymap1['e']=100;
//	mymap1['i']=60;
//	mymap1['p']=80;
//	mymap1['u']=100;
//
//	itlow = mymap1.lower_bound ('b');
//	std::cout << " lower bound " << std::endl;
//	std::cout << itlow->first << " ==> " << itlow->second << '\n';
//	itlow = mymap1.lower_bound ('c');
//	std::cout << itlow->first << " ==> " << itlow->second << '\n';
//	itlow = mymap1.lower_bound ('k');
//	std::cout << itlow->first << " ==> " << itlow->second << '\n';
//	std::cout << " upper bound " << std::endl;
//	itup = mymap1.upper_bound('d');
//	std::cout << itup->first << " ==> " << itup->second << '\n';
//	itup = mymap1.upper_bound('j');
//	std::cout << itup->first << " ==> " << itup->second << '\n';
//	itup = mymap1.upper_bound('t');
//	std::cout << itup->first << " ==> " << itup->second << '\n';
//	std::cout << "___________" << std::endl;
//	{
//	ft::map<char,int>::iterator itс = mymap1.find('b');
//	mymap1.erase(itс);
//	itс = mymap1.find('p');
//	mymap1.erase(itс, mymap1.end());
//	std::cout << "mymap1 contains:\n";
//	for (ft::map<char,int>::iterator it=mymap1.begin(); it!=mymap1.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//	std::cout << "___________" << std::endl;
//	}
//
//	{
//	ft::map<char,int> foo,bar;
//
//	foo['x']=100;
//	foo['y']=200;
//
//	bar['a']=11;
//	bar['b']=22;
//	bar['c']=33;
//
//	foo.swap(bar);
//
//	std::cout << "foo contains:\n";
//	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
//    std::cout << it->first << " => " << it->second << '\n';
//
//	std::cout << "bar contains:\n";
//	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
//    std::cout << it->first << " => " << it->second << '\n';
//	}
//
//		{
//		ft::map<char,int> mymap;
//
//		mymap['h']=111;
//		mymap['i']=222;
//		mymap['m']=333;
//		mymap['w']=444;
//
//		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
//		ret = mymap.equal_range('i');
//
//		std::cout << "lower bound points to: ";
//		std::cout << ret.first->first << " => " << ret.first->second << '\n';
//
//		std::cout << "upper bound points to: ";
//		std::cout << ret.second->first << " => " << ret.second->second << '\n';
//
//		ret = mymap.equal_range('p');
//
//		std::cout << "lower bound points to: ";
//		std::cout << ret.first->first << " => " << ret.first->second << '\n';
//
//		std::cout << "upper bound points to: ";
//		std::cout << ret.second->first << " => " << ret.second->second << '\n';
//	}
//
//	{
//		ft::map<char,int> first;
//
//		first['a']=10;
//		first['b']=30;
//		first['c']=50;
//		first['d']=70;
//
//		ft::map<char,int> second (first.begin(),first.end());
//		std::cout << "second contains:\n";
//		for (ft::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
//			std::cout << it->first << " => " << it->second << '\n';
//		ft::map<char,int> third (second);
//		std::cout << "third contains:\n";
//		for (ft::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
//			std::cout << it->first << " => " << it->second << '\n';
//		std::cout << "third size: " << third.size() << '\n';
//	}
//
//	{
//		ft::map<char,int> foo,bar;
//		foo['a']=100;
//		foo['b']=200;
//		bar['a']=10;
//		bar['z']=1000;
//
//		if (foo==bar) std::cout << "foo and bar are equal\n";
//		if (foo!=bar) std::cout << "foo and bar are not equal\n";
//		if (bar<foo) std::cout << "bar is less than foo\n";
//		if (foo>bar) std::cout << "foo is greater than bar\n";
//		if (bar<=foo) std::cout << "bar is less than or equal to foo\n";
//		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//	}
//
//	std::cout << "_____ft_____end______" << std::endl;
//	}
//	{
//	std::map<int, char> mymap;
//	mymap.begin();
//	mymap.end();
//	std::cout << "mymap is empty: " << mymap.empty() << std::endl;
//	mymap.insert(std::pair<int, int>(4, 'a'));
//	mymap.insert(std::pair<int, int>(7, 'b'));
//	std::cout << "starting a for loop " << std::endl;
//	for (int i = 0; i < 10; i++)
//		mymap.insert(std::pair<int, char>(i, i + 35));
//	mymap[11] = 'v';
//	std::cout << "mymap size: " << mymap.size() << std::endl;
//	std::map<int, char>::iterator it = mymap.begin();
//	it++;
//	std::cout << "mymap begin + 1: " << (*it).first << " " << (*it).second << std::endl;
//	std::map<int, char>::iterator ite = mymap.end();
//	ite--;
//	std::cout << "mymap end - 1: " << (*ite).first << " " << (*ite).second << std::endl;
//	ite--;
//	std::cout << "mymap end - 2: " << (*ite).first << " " << (*ite).second << std::endl;
//	ite--;
//	std::cout << "mymap end - 3: " << (*ite).first << " " << (*ite).second << std::endl;
//	std::map<int, char>::reverse_iterator rit = mymap.rend();
//	rit--;
//	std::cout << "mymap rend - 1: " << (*rit).first << " " << (*rit).second << std::endl;
//	std::map<int, char>::reverse_iterator rite = mymap.rbegin();
//	// rite++;
//	std::cout << "mymap rbegin + 1: " << (*rite).first << " " << (*rite).second << std::endl;
//	std::cout << "mymap count 11: " << mymap.count(11) << std::endl;
//	std::cout << "mymap count 12: " << mymap.count(12) << std::endl;
//
//	std::map<int,char> anothermap;
//	anothermap.insert(mymap.begin(),mymap.find(8));
//
//  // showing contents:
//	std::cout << "mymap contains:\n";
//	for (it=mymap.begin(); it!=mymap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//	std::cout << "anothermap contains:\n";
//	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//	std::map<char,int> mymap1;
//	std::map<char,int>::iterator itlow,itup;
//	mymap1['a']=20;
//	mymap1['b']=40;
//	mymap1['c']=60;
//	mymap1['d']=80;
//	mymap1['e']=100;
//	mymap1['i']=60;
//	mymap1['p']=80;
//	mymap1['u']=100;
//
//	itlow = mymap1.lower_bound ('b');
//	std::cout << " lower bound " << std::endl;
//	std::cout << itlow->first << " ==> " << itlow->second << '\n';
//	itlow = mymap1.lower_bound ('c');
//	std::cout << itlow->first << " ==> " << itlow->second << '\n';
//	itlow = mymap1.lower_bound ('k');
//	std::cout << itlow->first << " ==> " << itlow->second << '\n';
//	std::cout << " upper bound " << std::endl;
//	itup = mymap1.upper_bound('d');
//	std::cout << itup->first << " ==> " << itup->second << '\n';
//	itup = mymap1.upper_bound('j');
//	std::cout << itup->first << " ==> " << itup->second << '\n';
//	itup = mymap1.upper_bound('t');
//	std::cout << itup->first << " ==> " << itup->second << '\n';
//	std::cout << "___________" << std::endl;
//	{
//	std::map<char,int>::iterator itс = mymap1.find('b');
//	mymap1.erase(itс);
//	itс = mymap1.find('p');
//	mymap1.erase(itс, mymap1.end());
//	std::cout << "mymap1 contains:\n";
//	for (std::map<char,int>::iterator it=mymap1.begin(); it!=mymap1.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//	std::cout << "___________" << std::endl;
//	}
//	{
//	std::map<char,int> foo,bar;
//
//	foo['x']=100;
//	foo['y']=200;
//
//	bar['a']=11;
//	bar['b']=22;
//	bar['c']=33;
//
//	foo.swap(bar);
//
//	std::cout << "foo contains:\n";
//	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
//    std::cout << it->first << " => " << it->second << '\n';
//
//	std::cout << "bar contains:\n";
//	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//	}
//
//	{
//		std::map<char,int> mymap;
//
//		mymap['h']=111;
//		mymap['i']=222;
//		mymap['m']=333;
//		mymap['w']=444;
//
//		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
//		ret = mymap.equal_range('i');
//
//		std::cout << "lower bound points to: ";
//		std::cout << ret.first->first << " => " << ret.first->second << '\n';
//
//		std::cout << "upper bound points to: ";
//		std::cout << ret.second->first << " => " << ret.second->second << '\n';
//
//		ret = mymap.equal_range('p');
//
//		std::cout << "lower bound points to: ";
//		std::cout << ret.first->first << " => " << ret.first->second << '\n';
//
//		std::cout << "upper bound points to: ";
//		std::cout << ret.second->first << " => " << ret.second->second << '\n';
//	}
//
//	{
//		std::map<char,int> first;
//
//		first['a']=10;
//		first['b']=30;
//		first['c']=50;
//		first['d']=70;
//
//		std::map<char,int> second (first.begin(),first.end());
//		std::cout << "second contains:\n";
//		for (std::map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
//			std::cout << it->first << " => " << it->second << '\n';
//		std::map<char,int> third (second);
//		std::cout << "third contains:\n";
//		for (std::map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
//			std::cout << it->first << " => " << it->second << '\n';
//	}
//
//	{
//		std::map<char,int> foo,bar;
//		foo['a']=100;
//		foo['b']=200;
//		bar['a']=10;
//		bar['z']=1000;
//
//		if (foo==bar) std::cout << "foo and bar are equal\n";
//		if (foo!=bar) std::cout << "foo and bar are not equal\n";
//		if (bar<foo) std::cout << "bar is less than foo\n";
//		if (foo>bar) std::cout << "foo is greater than bar\n";
//		if (bar<=foo) std::cout << "bar is less than or equal to foo\n";
//		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//	}
//
//	}
	std::map<int, int> m;
	m.insert(std::make_pair(1, 2));
	m.insert(std::make_pair(2, 2));
	m.insert(std::make_pair(3, 2));
	m.insert(std::make_pair(4, 2));
	const std::map<int, int> m2(m);
	std::map<int, int>::const_iterator it = m2.begin();
//	it->second = 42;

	ft::map<int, int> m0;
	m0.insert(ft::make_pair(1, 2));
	m0.insert(ft::make_pair(2, 2));
	m0.insert(ft::make_pair(3, 2));
	m0.insert(ft::make_pair(4, 2));
	const ft::map<int, int> m1(m0);
	ft::map<int, int>::const_iterator it0 = m1.begin();
	it0->second = 42;
//	m1[(*it0).first]

	return 0;
}
