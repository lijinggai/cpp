#pragma once
#include<iostream>
#include <vector>
#include <string>
using namespace std;

template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
// 特化
template<>
struct Hash<string>
{
	size_t operator()(const string& s)
	{
		size_t value = 0;
		for (auto e : s)
		{
			// BKDR,减少哈希冲突
			value *= 31;
			value += e;
		}
		return value;
	}
};
namespace HashTable
{
	template<class T, class V>
	struct HashNode
	{
		pair<T, V> _kv;
		HashNode<T, V>* _next;
	};

	template<class T, class V>
	class HashTable
	{
		typedef HashNode<T, V> Node;
	public:
		bool Erase(const K& key)
		{
			if (_tables.empty())
			{
				return false;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr) // 头删
					{
						_tables[index] = cur->_next;
					}
					else // 中间删除
					{
						prev->_next = cur->_next;
					}

					--_n;

					delete cur;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}
		Node* Find(const K& key)
		{
			if (_tables.empty())
			{
				return nullptr;
			}

			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}

			return nullptr;
		}
		bool Insert(const pair<K, V>& kv)
		{
			Node* ret = Find(kv.first);
			if (ret)
				return false;

			HashFunc hf;
			// 负载因子 == 1时扩容
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				newTables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t index = hf(cur->_kv.first) % newTables.size();
						// 头插
						cur->_next = newTables[index];
						newTables[index] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			size_t index = hf(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			// 头插
			newnode->_next = _tables[index];
			_tables[index] = newnode;

			++_n;
			return true;
		}
	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};
}