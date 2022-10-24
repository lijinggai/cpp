#pragma once
#include<iostream>
using namespace std;
template<class K, class V>
struct AVLtreeNode
{
	AVLtreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
		,_kv(kv)
	{}
	AVLtreeNode<K, V>* _left;
	AVLtreeNode<K, V>* _right;
	AVLtreeNode<K, V>* _parent;

	int _bf;//平衡因子

	pair<K, V> _kv;
};
template<class K,class V>
class AVLtree
{
	typedef AVLtreeNode<K, V> Node;
public:
	AVLtree()
		:_root(nullptr)
	{}
	void RotateL(Node* parent);
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}

		subL->_bf = parent->_bf = 0;
	}
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = _root, *cur = _root;
		while (cur)
		{
			if (cur->_kv.first > _root->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first < _root->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//
		cur = new Node(kv);
		if (cur->_kv.first > parent->_kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
			while (parent)
			{
				if (parent->_right == cur)
					parent->_bf++;
				else
					parent->_bf--;
				if (parent->_bf == 0)
				{
					break;
				}
				if (parent->_bf == 1 ||parent->_bf== -1)
				{
					//当前节点所在子树变了，会影响父亲
					// 继续往上更新
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//parent所在子树已经不平衡，需要旋转处理一下
					if (parent->_bf == -2)
					{
						if (cur->_bf == -1)
						{
							// 右单旋
							RotateR(parent);
						}
						else // cur->_bf == 1
						{
							RotateLR(parent);
						}
					}
					else // parent->_bf  == 2
					{
						if (cur->_bf == 1)
						{
							// 左单旋
							RotateL(parent);
						}
						else // cur->_bf == -1
						{
							RotateRL(parent);
						}
					}
					break;
				}
				else
				{
					// 插入节点之前，树已经不平衡了，或者bf出错。需要检查其他逻辑
					assert(false);
				}
				
			}
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		return true;
	}
	Node* Find(const K& kv)
	{}
	bool Erase(const K& kv)
	{}
private:
	Node* _root;
};