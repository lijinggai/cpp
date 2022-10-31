#pragma once
#include"RBTree.h"

namespace lj
{
	template<class K>
	class set
	{
	public:

		struct setDataOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};

		typedef typename RBtree<K, K, setDataOfT>::iterator iterator;
		iterator begin()
		{
			return _s.begin();
		}

		iterator end()
		{
			return _s.end();

		}
		bool insert(const K& k)
		{
			_s.Insert(k);
			return true;
		}
	private:
		RBtree<K, K, setDataOfT> _s;
	};
}