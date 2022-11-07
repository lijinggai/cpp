#pragma once
#include<iostream>
#include<vector>
using namespace std;

enum Status
{
	EXIST,
	EMPTY,
	DELETE,
};
template<class T, class V>
struct HashData
{
	pair<T, V> _kv;
	Status _status;
};
template<class T, class V>
class HashTable
{
	//typedef HashData<T, V> Node;
public:
	bool Insert(const pair<T, V>& kv)
	{
		// 负载因子到0.7，就扩容
		// 负载因子越小，冲突概率越低，效率越高，空间浪费越多
		// 负载因子越大，冲突概率越高，效率越低，空间浪费越少
		if (_tables.size()==0 || _n * 10 / _tables.size() >= 7)
		{
			//扩容
			size_t newHashSize = _tables.size() == 0 ? 0 : _tables.size * 2;
			HashTable<T, V> newHT;
			newHT._tables.resize(newHashSize);
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._status == EXIST)
				{
					newHT.Insert(_tables[i]._kv);
				}
			}
			_tables.swap(newHT);
		}
		size_t start = kv.first % _tables.size();
		size_t i = 0;
		size_t index = start;
		// 线性探测 or 二次探测
		while (_tables[index] == EXIST)
		{
			i++;
			index += i * i;
			//index += i;
			index &= _tables.size();
		}
		_tables[index]._kv = kv;
		_tables[index].status = EXIST;
		++_n;
	}
private:
	vector<HashData<T, V>> _tables;
	size_t _n;
};
//
//#pragma once
//#include <vector>
//
//namespace CloseHash
//{
//	enum Status
//	{
//		EXIST,
//		EMPTY,
//		DELETE
//	};
//
//	template<class K, class V>
//	struct HashData
//	{
//		pair<K, V> _kv;
//		Status _status = EMPTY;
//	};
//
//	template<class K>
//	struct Hash
//	{
//		size_t operator()(const K& key)
//		{
//			return key;
//		}
//	};
//
//	// 特化
//	template<>
//	struct Hash < string >
//	{
//		size_t operator()(const string& s)
//		{
//			// BKDR
//			size_t value = 0;
//			for (auto ch : s)
//			{
//				value *= 31;
//				value += ch;
//			}
//			return value;
//		}
//	};
//
//
//	//struct HashStr
//	//{
//	//	size_t operator()(const string& s)
//	//	{
//	//		// BKDR
//	//		size_t value = 0;
//	//		for (auto ch : s)
//	//		{
//	//			value *= 31;
//	//			value += ch;
//	//		}
//	//		return value;
//	//	}
//	//};
//
//	template<class K, class V, class HashFunc = Hash<K>>
//	class HashTable
//	{
//	public:
//		bool Erase(const K& key)
//		{
//			HashData<K, V>* ret = Find(key);
//			if (ret == nullptr)
//			{
//				return false;
//			}
//			else
//			{
//				--_n;
//				ret->_status = DELETE;
//				return true;
//			}
//		}
//
//		HashData<K, V>* Find(const K& key)
//		{
//			if (_tables.size() == 0)
//			{
//				return nullptr;
//			}
//
//			HashFunc hf;
//			size_t start = hf(key) % _tables.size();
//			size_t i = 0;
//			size_t index = start;
//			// 线性探测 or 二次探测
//			while (_tables[index]._status != EMPTY)
//			{
//				if (_tables[index]._kv.first == key && _tables[index]._status == EXIST)
//				{
//					return &_tables[index];
//				}
//
//				++i;
//				//index = start + i*i;
//				index = start + i;
//
//				index %= _tables.size();
//			}
//
//			return nullptr;
//		}
//
//		bool Insert(const pair<K, V>& kv)
//		{
//			HashData<K, V>* ret = Find(kv.first);
//			if (ret)
//			{
//				return false;
//			}
//
//			// 负载因子到0.7，就扩容
//			// 负载因子越小，冲突概率越低，效率越高，空间浪费越多
//			// 负载因子越大，冲突概率越高，效率越低，空间浪费越少
//			if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
//			{
//				// 扩容
//				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//				//vector<HashData<K, V>> newTables;
//				//newTables.resize(newSize);
//				//// 遍历原表，把原表中的数据，重新按newSize映射到新表
//				//for (size_t i = 0; i < _tables.size(); ++i)
//				//{
//				//	// 
//				//}
//				//_tables.swap(newTables);
//				HashTable<K, V, HashFunc> newHT;
//				newHT._tables.resize(newSize);
//				for (size_t i = 0; i < _tables.size(); ++i)
//				{
//					if (_tables[i]._status == EXIST)
//					{
//						newHT.Insert(_tables[i]._kv);
//					}
//				}
//
//				_tables.swap(newHT._tables);
//			}
//
//			HashFunc hf;
//			size_t start = hf(kv.first) % _tables.size();
//			size_t i = 0;
//			size_t index = start;
//			// 线性探测 or 二次探测
//			while (_tables[index]._status == EXIST)
//			{
//				++i;
//				//index = start + i*i;
//				index = start + i;
//
//				index %= _tables.size();
//			}
//
//			_tables[index]._kv = kv;
//			_tables[index]._status = EXIST;
//			++_n;
//
//			return true;
//		}
//
//	private:
//		vector<HashData<K, V>> _tables;
//		size_t _n = 0;	// 有效数据个数
//	};
//
//	void TestHashTable1()
//	{
//		//HashTable<int, int, Hash<int>> ht;
//		HashTable<int, int> ht;
//
//		int a[] = { 2, 12, 22, 32, 42, 52, 62 };
//		for (auto e : a)
//		{
//			ht.Insert(make_pair(e, e));
//		}
//
//		ht.Insert(make_pair(72, 72));
//		ht.Insert(make_pair(32, 32));
//		ht.Insert(make_pair(-1, -1));
//		ht.Insert(make_pair(-999, -999));
//
//		Hash<int> hs;
//		cout << hs(9) << endl;
//		cout << hs(-9) << endl;
//
//		cout << ht.Find(12) << endl;
//		ht.Erase(12);
//		cout << ht.Find(12) << endl;
//	}
//
//	struct Date
//	{
//
//
//	};
//
//	struct HashDate
//	{
//		size_t operator()(const Date& d)
//		{
//			//...
//		}
//	};
//
//	void TestHashTable2()
//	{
//		/*HashStr hs;
//		cout << hs("sort")<<endl;
//		cout << hs("insert") << endl;
//		cout << hs("eat") << endl;
//		cout << hs("ate") << endl;
//		cout << hs("abcd") << endl;
//		cout << hs("aadd") << endl;*/
//
//		HashTable<string, string> ht;
//		ht.Insert(make_pair("sort", "排序"));
//		ht.Insert(make_pair("string", "字符串"));
//
//		// 当key是一个定义类型时，需要配置一个仿函数，将key转成整形
//		HashTable<Date, string, HashDate> htds;
//	}
//}
//
//namespace LinkHash
//{
//	template<class K, class V>
//	struct HashNode
//	{
//		pair<K, V> _kv;
//		HashNode<K, V>* _next;
//	};
//
//	template<class K, class V, class HashFunc = Hash<K>>
//	class HashTable
//	{
//		typedef HashNode<K, V> Node;
//	public:
//		Node* Find(const K& key)
//		{
//
//		}
//
//		bool Insert(const pair<K, V>& kv)
//		{
//			Node* ret = Find(kv.first);
//			if (ret)
//				return false;
//
//			// 负载因子 == 1时扩容
//			if (_n == _tables.size())
//			{
//				size_t newSize = _tables.size() == 0 ？ 10 : _tables.size() * 2;
//				// ...
//				vector<Node*> newTables;
//				newTables.resize(newSize);
//				// ...
//			}
//
//			HashFunc hf;
//			size_t index = hf(kv.first) % _tables.size();
//			Node* newnode = new Node(kv);
//			// 头插
//			newnode->_next = _tables[index];
//			_tables[index] = newnode;
//
//			++_n;
//			return true;
//		}
//
//	private:
//		vector<Node*> _tables;
//		size_t _n = 0;  // 有效数据的个数
//	};
//}