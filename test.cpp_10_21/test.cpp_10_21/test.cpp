void test_map1()
{
	map<int, double> m;
	//调用pair的构造函数，构造一个匿名对象来插入
	m.insert(pair<int, double>(1, 1.2));
	m.insert(pair<int, double>(3, 3.2));
	m.insert(pair<int, double>(2, 2.2));

	//调用函数模板，构造对象
	//好处：不需要声明pair的模板参数，让编译器推演，写起来更方便
	m.insert(make_pair(4, 4.2));
	map<int, double>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << *it << endl;
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	// 通过typedef 简化命名
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;

	DICT dict;
	dict.insert(DICT_KV("insert", "插入"));
	dict.insert(std::make_pair("sort", "排序"));
	dict.insert(std::make_pair("left", "左边"));

	DICT_ITER dit = dict.begin();
	//auto dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}
void test_map2()
{
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;

	DICT dict;
	dict.insert(DICT_KV("insert", "插入"));
	dict.insert(DICT_KV("sort", "排序"));
	dict.insert(DICT_KV("left", "左边"));

	DICT_ITER dit = dict.begin();
	while (dit != dict.end())
	{
		dit->second.insert(0, "{");
		dit->second += "}";

		++dit;
	}
	cout << endl;

	dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;

	// 修改map的value数据
	auto ret = dict.find("left");
	if (ret != dict.end())
	{
		//ret->second.insert(ret->second.size() - 1, "、剩余");
		// 可读性优化技巧
		string& str = ret->second;
		str.insert(str.size() - 1, "、剩余");
	}

	dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}
void test_map3()
{
	//统计
	string arr[] = { "足球","足球", "足球", "篮球", "足球", "足球","篮球","乒乓球","篮球","乒乓球","乒乓球", };
	map<string, int> countMap;
	//引用，不用深拷贝
	//for (const auto& str : arr)
	//{
	//	map<string, int>::iterator it = countMap.find(str);
	//	//在map中没有找到插入，找到++
	//	if (it != countMap.end())
	//	{
	//		it->second++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(str, 1));
	//	}
	//}
	//for (const auto& e : countMap)
	//{
	//	cout << e.first << ":" << e.second<<endl;
	//}
	//2
	//for (const auto& str : arr)
	//{
	//	//先插入，如果str已经在map中，insert会放回str所在节点的迭代器，再++；
	//	pair<map<string,int>::iterator, bool> it = countMap.insert(make_pair(str,1));
	//	if (it.second ==false )
	//	{
	//		it.first->second++;
	//	}
	//}
	//3
	for (const auto& str : arr)
	{
		countMap[str]++;
	}
	for (const auto& e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
	map<string, string> dict;
	dict.insert(make_pair("right", "右边"));
	dict["key"] = "关键";//插入+修改
	dict["insert"];//插入
	dict["insert"] = "插入";//修改
	dict["right"] = "右边，正确";//修改
}
struct compare
{
	bool operator()(map<string, int>::iterator x, map<string, int>::iterator y)
	{
		return x->second < y->second;
	}
};
void test_map4()
{
	string arr[] = { "足球","足球", "足球", "篮球", "足球", "足球","篮球","乒乓球","篮球","乒乓球","乒乓球", };
	map<string, int> countMap;
	for (const auto& str : arr)
	{
		countMap[str]++;
	}
	vector<map<string, int>::iterator> v;
	map<string, int>::iterator countMapit = countMap.begin();
	while (countMapit != countMap.end())
	{
		v.push_back(countMapit);
		++countMapit;
	}
	sort(v.begin(), v.end(), compare());
	// 利用map排序  -- 拷贝pair数据
//map<int, string> sortMap;
	map<int, string, greater<int>> sortMap;
	for (auto e : countMap)
	{
		sortMap.insert(make_pair(e.second, e.first));
	}
	// 利用set排序  --不拷贝pair数据
	set<map<string, int>::iterator, compare> sortSet;
	countMapit = countMap.begin();
	while (countMapit != countMap.end())
	{
		sortSet.insert(countMapit);
		++countMapit;
	}
}
