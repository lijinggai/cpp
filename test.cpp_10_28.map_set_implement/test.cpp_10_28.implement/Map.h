#pragma once
#include"RBTree.h"

namespace lj
{
	template<class K, class V>
	class map
	{
	public:
		struct mapDataOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
		bool insert(const pair<const K, V>& kv)
		{
			_m.Insert(kv);
			return true;
		}
	private:
		RBtree<K, pair<const K, V>, mapDataOfT> _m;
	};
}
