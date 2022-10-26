#pragma once
#include<iostream>
using namespace std;
enum Colour
{
	RED,
	BLACK,
};
template<class K, class V>
struct RBtreeNode
{
	RBtreeNode(const pair<K,V> kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(RED)
	{}

	RBtreeNode<K, V>* _left;
	RBtreeNode<K, V>* _right;
	RBtreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col


};
template<class K,class V>
class RBtree
{
	typedef RBtreeNode Node;
public:
	RBtree()
		:_root(nullptr)
	{}
	
	~RBTree()
	{
		Destory(_root);
		_root = nullptr;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}

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
	}
	pair<Node*, bool> Insert(const pair<K, V> kv)
	{
		Node* cur = _root,*parent=_root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return pair<cur, false>;
			}
		}
		Node* newnode = new Node(kv);
		newnode->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		cur = newnode;
		while (parent && parent->_col == RED)
		{
			// 如果父亲存在，且颜色为红色就需要处理
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				// 关键是看叔叔
				Node* uncle = grandfather->_right;
				// 情况1：uncle存在且为红
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = RED;
					grandfather->_col = RED;
					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else// 情况2+3：uncle不存在 uncle存在且为黑
				{
					// 情况2：单旋
					if (cur == parent->_left)
					{
						rotateR(grandfather);

						parent->_kv = BLACK ;
						grandfather->_kv = RED;
					}
					// 情况3：双旋
					else
					{
						RotateL(parent);
						RotateR(grandfather);

						cur->_kv = BLACK;
						grandfather->_kv = RED;
					}
				}
			}
			// 如果父亲存在，且颜色为红色就需要处理
			else
			{
				// 关键是看叔叔
				Node* uncle = grandfather->_left;
				// 情况1：uncle存在且为红
				if (uncle && uncle->_kv == RED)
				{
					parent->_kv = uncle->_kv = RED;
					grandfather->_kv = RED;
					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // 情况2 + 3：uncle不存在 uncle存在且为黑
				{
					// 情况2：单旋
					if (cur == parent->_right)
					{
						RotateL(grandfather);

						parent->_kv = BLACK;
						grandfather->_kv = RED;
					}
					// 情况3：双旋
					else
					{
						RotateR(parent);
						RotateL(grandfather);

						cur->_kv = BLACK;
						grandfather->_kv = RED;
					}
				}
			}
		}
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}
private:
	void Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destory(root->_left);
		Destory(root->right);
		delete root;
	}
	Node* _root;

};