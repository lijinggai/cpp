#pragma once
#include <bitset>
#include <string>
#include <time.h>
#include<iostream>
using namespace std;

//不同的字符串用得到整形不一样
struct BKDRHash
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};

struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct DJBHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

template<size_t N,
	size_t X = 8,
	class K = string,
	class HashFunc1 = BKDRHash,
	class HashFunc2 = APHash,
	class HashFunc3 = DJBHash>
//x=8,char有8个比特位，N是char的数量
class BloomFilter
{
public:
	//映射3个位置
	void Set(const K& key)
	{
		size_t len = X * N;
		size_t index1 = HashFunc1()(key) % len;
		size_t index2 = HashFunc2()(key) % len;
		size_t index3 = HashFunc3()(key) % len;

		_bs.set(index1);
		_bs.set(index2);
		_bs.set(index3);
	}
	//映射3个位置，有一个位置不在说明就不在，如果都在也有可能是误判
	bool Test(const K& key)
	{
		size_t len = X * N;
		size_t index1 = HashFunc1()(key) % len;
		if (_bs.test(index1) == false)
			return false;

		size_t index2 = HashFunc2()(key) % len;
		if (_bs.test(index2) == false)
			return false;

		size_t index3 = HashFunc3()(key) % len;

		if (_bs.test(index3) == false)
			return false;

		return true;  // 存在误判的
	}

	// 不支持删除，删除可能会影响其他值。
	void Reset(const K& key);
private:
	bitset<X* N> _bs;
};
