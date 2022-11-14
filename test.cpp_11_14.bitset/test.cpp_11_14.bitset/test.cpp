#pragma once
#include <vector>

namespace bit
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 8 + 1, 0);
		}

		void set(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;

			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;

			_bits[i] &= (~(1 << j));
		}

		bool test(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;

			return _bits[i] & (1 << j);
		}

	private:
		std::vector<char> _bits;
		//std::vector<int> _bits;
	};

	void test_bitset()
	{
		/*bitset<100> bs;
		bs.set(5);
		bs.set(4);
		bs.set(10);
		bs.set(20);

		cout << bs.test(5) << endl;
		cout << bs.test(4) << endl;
		cout << bs.test(10) << endl;
		cout << bs.test(20) << endl;
		cout << bs.test(21) << endl;
		cout << bs.test(6) << endl << endl;

		bs.reset(20);
		bs.reset(10);
		bs.reset(5);

		cout << bs.test(5) << endl;
		cout << bs.test(4) << endl;
		cout << bs.test(10) << endl;
		cout << bs.test(20) << endl;
		cout << bs.test(21) << endl;
		cout << bs.test(6) << endl;*/

		//bitset<0xffffffff> bs;
		bitset<-1> bs;
	}
}


template<size_t N>
class TwoBitSet
{
public:
	void Set(size_t x)
	{
		if (!_bs1.test(x) && !_bs2.test(x)) // 00 -> 01
		{
			_bs2.set(x);
		}
		else if (!_bs1.test(x) && _bs2.test(x)) // 01 -> 10
		{
			_bs1.set(x);
			_bs2.reset(x);
		}
		// 10 表示已经出现2次或以上，不用处理
	}

	void PrintOnceNum()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (!_bs1.test(i) && _bs2.test(i)) // 01
			{
				cout << i << endl;
			}
		}
	}
private:
	bit::bitset<N> _bs1;
	bit::bitset<N> _bs2;
};

void TestTwoBitSet()
{
	int a[] = { 99,0,4,50,33,44,2,5,99,0,50,99,50,2 };
	TwoBitSet<100> bs;
	for (auto e : a)
	{
		bs.Set(e);
	}

	bs.PrintOnceNum();
}

//void TestFindIntersection()
//{
//	int a1[] = { 5, 30, 1, 99, 10 };
//	int a2[] = { 8, 10, 11, 9, 30, 10, 30};
//}