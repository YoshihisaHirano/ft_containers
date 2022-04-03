#include "map.hpp"
#include <iostream>
#include <map>

int main()
{
	{
	ft::map<int, char> mymap;
	mymap.begin();
	mymap.end();
	std::cout << "mymap is empty: " << mymap.empty() << std::endl;
	mymap.insert(ft::pair<int, int>(4, 'a'));
	mymap.insert(ft::pair<int, int>(7, 'b'));
	std::cout << "starting a for loop " << std::endl;
	for (int i = 0; i < 10; i++)
		mymap.insert(ft::pair<int, char>(i, i + 35));
	// mymap.print();
	mymap[11] = 'v';
	std::cout << "mymap size: " << mymap.size() << std::endl;
	ft::map<int, char>::iterator it = mymap.begin();
	it++;
	std::cout << "mymap begin + 1: " << *it << std::endl;
	ft::map<int, char>::iterator ite = mymap.end();
	ite--;
	std::cout << "mymap end - 1: " << *ite << std::endl;
	ite--;
	std::cout << "mymap end - 2: " << *ite << std::endl;
	ite--;
	std::cout << "mymap end - 3: " << *ite << std::endl;
	ft::map<int, char>::reverse_iterator rit = mymap.rend();
	rit--;
	std::cout << "mymap rend - 1: " << *rit << std::endl;
	ft::map<int, char>::reverse_iterator rite = mymap.rbegin();
	// rite++;
	std::cout << "mymap rbegin + 1: " << *rite << std::endl;
	std::cout << "mymap count 11: " << mymap.count(11) << std::endl;
	std::cout << "mymap count 12: " << mymap.count(12) << std::endl;

	ft::map<int,char> anothermap;
	anothermap.insert(mymap.begin(),mymap.find(8));

  // showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::map<char,int> mymap1;
	ft::map<char,int>::iterator itlow,itup;
	mymap1['a']=20;
	mymap1['b']=40;
	mymap1['c']=60;
	mymap1['d']=80;
	mymap1['e']=100;
	mymap1['i']=60;
	mymap1['p']=80;
	mymap1['u']=100;

	itlow = mymap1.lower_bound ('b');
	std::cout << " lower bound " << std::endl;
	std::cout << itlow->first << " ==> " << itlow->second << '\n';
	itlow = mymap1.lower_bound ('c');
	std::cout << itlow->first << " ==> " << itlow->second << '\n';
	itlow = mymap1.lower_bound ('k');
	std::cout << itlow->first << " ==> " << itlow->second << '\n';
	std::cout << " upper bound " << std::endl;
	itup = mymap1.upper_bound('d');
	std::cout << itup->first << " ==> " << itup->second << '\n';
	itup = mymap1.upper_bound('j');
	std::cout << itup->first << " ==> " << itup->second << '\n';
	itup = mymap1.upper_bound('t');
	std::cout << itup->first << " ==> " << itup->second << '\n';
	std::cout << "___________" << std::endl;
	ft::map<char,int>::iterator itс = mymap1.find('b');
	mymap1.erase (itс);
	std::cout << "_____ft_____end______" << std::endl;
	}
	{
	std::map<int, char> mymap;
	mymap.begin();
	mymap.end();
	std::cout << "mymap is empty: " << mymap.empty() << std::endl;
	mymap.insert(std::pair<int, int>(4, 'a'));
	mymap.insert(std::pair<int, int>(7, 'b'));
	std::cout << "starting a for loop " << std::endl;
	for (int i = 0; i < 10; i++)
		mymap.insert(std::pair<int, char>(i, i + 35));
	// mymap.print();
	mymap[11] = 'v';
	std::cout << "mymap size: " << mymap.size() << std::endl;
	std::map<int, char>::iterator it = mymap.begin();
	it++;
	std::cout << "mymap begin + 1: " << (*it).first << " " << (*it).second << std::endl;
	std::map<int, char>::iterator ite = mymap.end();
	ite--;
	std::cout << "mymap end - 1: " << (*ite).first << " " << (*ite).second << std::endl;
	ite--;
	std::cout << "mymap end - 2: " << (*ite).first << " " << (*ite).second << std::endl;
	ite--;
	std::cout << "mymap end - 3: " << (*ite).first << " " << (*ite).second << std::endl;
	std::map<int, char>::reverse_iterator rit = mymap.rend();
	rit--;
	std::cout << "mymap rend - 1: " << (*rit).first << " " << (*rit).second << std::endl;
	std::map<int, char>::reverse_iterator rite = mymap.rbegin();
	// rite++;
	std::cout << "mymap rbegin + 1: " << (*rite).first << " " << (*rite).second << std::endl;
	std::cout << "mymap count 11: " << mymap.count(11) << std::endl;
	std::cout << "mymap count 12: " << mymap.count(12) << std::endl;

	std::map<int,char> anothermap;
	anothermap.insert(mymap.begin(),mymap.find(8));

  // showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	}

	std::map<char,int> mymap1;
	std::map<char,int>::iterator itlow,itup;
	mymap1['a']=20;
	mymap1['b']=40;
	mymap1['c']=60;
	mymap1['d']=80;
	mymap1['e']=100;
	mymap1['i']=60;
	mymap1['p']=80;
	mymap1['u']=100;

	itlow = mymap1.lower_bound ('b');
	std::cout << " lower bound " << std::endl;
	std::cout << itlow->first << " ==> " << itlow->second << '\n';
	itlow = mymap1.lower_bound ('c');
	std::cout << itlow->first << " ==> " << itlow->second << '\n';
	itlow = mymap1.lower_bound ('k');
	std::cout << itlow->first << " ==> " << itlow->second << '\n';
	std::cout << " upper bound " << std::endl;
	itup = mymap1.upper_bound('d');
	std::cout << itup->first << " ==> " << itup->second << '\n';
	itup = mymap1.upper_bound('j');
	std::cout << itup->first << " ==> " << itup->second << '\n';
	itup = mymap1.upper_bound('t');
	std::cout << itup->first << " ==> " << itup->second << '\n';
	std::cout << "___________" << std::endl;
	std::map<char,int>::iterator itс = mymap1.find('b');
	mymap1.erase (itс);
	return 0;
}
