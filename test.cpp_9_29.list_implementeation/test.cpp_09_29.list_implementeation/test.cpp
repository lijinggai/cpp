#include<iostream>
#include<assert.h>
using namespace std;

namespace lj
{
	template<class T>
	struct _list_node//stryct全为公有
	{
		T _val;
		_list_node<T>* _prev;
		_list_node<T>* _next;
		_list_node(const T x = T())
			:_val(x)
			,_prev(nullptr)
			,_next(nullptr)
		{}
	};
	/*typedef _list_iterator<T, T&, T*> iterator;
	typedef _list_iterator<T, const T&, const T*> const_iterator;*/
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> self;

		node* _pnode;

		_list_iterator(node* pnode)//构造函数
			:_pnode(pnode)
		{}
		// 拷贝构造、operator=、析构我们不写，编译器默认生成就可以用
		Ref operator*()
		{
			return _pnode->_val;
		}
		Ptr operator->()
		{
			return &_pnode->_val;
		}
		bool operator!=(const self& s)const
		{
			return _pnode != s._pnode;
		}
		bool operator==(const self& s) const
		{
			return _pnode == s._pnode;
		}
		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}

		// it++ -> it.operator++(&it, 0)
		self operator++(int)
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}

		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
	};
	class Date
	{
	public:
		int _year = 0;
		int _month = 1;
		int _day = 1;
	};
	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;//类模板会实例化两个例子
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}
		list()//构造函数
		{
			_head = new node;
			_head -> _prev = _head;
			_head -> _next = _head;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		list(const list<T>& lt)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}
		// copy = lt1;
		list<T>& operator=(list<T> lt)
		{
			swap(_head, lt._head);

			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
				//erase(it++);
			}
		}
		//void push_back(const T& x)//尾插
		//{
		//	node* newnode = new node(x);
		//	node* tail = _head->_prev;
		//	
		//	tail->_next = newnode;
		//	newnode->_prev = tail;
		//	newnode->_next = _head;
		//	_head->_prev = newnode;
		//}
		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}
		void insert(iterator pos, const T& x)//插入不会迭代器失效
		{
			assert(pos._pnode);
			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		iterator erase(iterator pos)//删除如果没有返回值会导致迭代器失效
		{
			assert(pos._pnode);
			assert(pos!=end());
			node* next = pos._pnode->next;
			node* prev = pos._pnode->prev;

			delete pos._pnode;
			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}
		bool empty()
		{
			return begin() == end();
		}
	private:
		node* _head;
	};
	void PrintList(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			// *it += 1; // ?
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	
	void test_list()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		PrintList(lt);
	}
	void test_list1()
	{
		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());
		lt.push_back(Date());
		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << it->_year << " ";
			cout << it->_month << " ";
			cout << it->_day << " ";
			++it;
			cout << endl;

		}
		cout << endl;
	}

}
int main()
{
	//lj::test_list();
	lj::test_list1();
	return 0;
}