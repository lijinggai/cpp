#include"RBTree.h"
#include"Set.h"
#include"Map.h"
int main()
{
	lj::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(0, 0));
	m.insert(make_pair(9, 9));


	lj::set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(1);
	s.insert(13);
	s.insert(0);
	s.insert(15);
	s.insert(18);


	lj::set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;


	return 0;
	return 0;
}