#pragma once
#include<iostream>
using namespace std;

template<class K>
struct BinarySearchNode
{
	BinarySearchNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
	BinarySearchNode<K>* _left;
	BinarySearchNode<K>* _right;
	K _key;
};
template<class K>
class BSTree
{
	typedef BinarySearchNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}
	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _FindR(Node* root,const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->_key < key)
		{
			return _FindR(root->left, key);
		}
		else if (root->_key > key)
		{
			return _FindR(root->right, key);

		}
		else
		{
			return root;
		}
	}
	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
		{
			return _InsertR(root->_right, key);//引用别名，不需要多建一个父节点变量
		}
		else if (root->_key > key)
		{
			return _InsertR(root->_left, key);

		}
		else
		{
			return false;
		}
	}
	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _EraseR(root->_left, key);

		}
		else
		{
			if (root->_left == nullptr)
			{
					Node* del = root;
					root = root->_right;
					delete del;
			}
			else if (root->_right == nullptr)
			{
					Node* del = root;
					root = root->_left;
					delete del;
			}
			else
			{
				Node* minRight = root->_right;
				while (minRight->_left)
				{
					minRight = minRight->_left;
				}
				K min = minRight->_key;

				// 转换成在root的右子树删除min
				_EraseR(root->_right, min);
				root->_key = min;
			}
			return true;
		}
	}
	
	Node* _root;
};