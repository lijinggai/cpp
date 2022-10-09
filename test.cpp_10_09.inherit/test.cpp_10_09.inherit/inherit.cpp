#include<iostream>
#include<string>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//	string _addr;
//protected:
//	string _name; // 姓名
//private:
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	void funcprotected()
//	{
//		cout << _name << endl;
//	}
//	void func()
//	{
//		//基类继承下来的私有成员不可见:内存上，派生类对象有这个成员，但是语法规定了我们不能去访问
//		cout << _age << endl;
//	}
//protected:
//	int _stunum; // 学号
//};
//int main()
//{
//	Student s;
//	s._addr;
//	s.funcprotected();
//	s.func();
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//	string _name; // 姓名
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _stunum; // 学号
//};
//int main()
//{
//	Person p;
//	Student s;
//	s._name = "李四";
//	s._age = 20;
//	s._stunum = 100234;
//
//	p = s;//父<-子，切片/切割
//	Person* ptr = &s;//指针指向子类对象，ptr只能访问继承的父类成员
//	Person& ref = s;//子类对象中包含父类部分成员的别名
//}

////Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//int main()
//{
//	Student s;
//	s.Print();
//}

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//}

//class Person
//{
//public:
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//
//	~Person() // -> 因为后面多态的一些原因，任何类析构函数名都会被统一处理成destructor()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int id)
//		: Person(name)
//		,_id(id)
//	{
//		// 调用父类构造函数初始化继承的父类部分
//		// 再初始化自己的成员
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		:Person(s)  // ->s传递给Person& s 是一个切片行为
//		, _id(s._id)
//	{
//		// 类似构造函数
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		// 同上
//		if (this != &s)
//		{
//			// 小心这里是隐藏
//			Person::operator=(s);
//			_id = s._id;
//		}
//		cout << "Student& operator=(const Student& s)" << endl;
//		return *this;
//	}
//
//	~Student() // 编译器认为子类的析构函数和父类的析构函数构成隐藏
//	{
//		//Person::~Person(); // 所以这里想调用，需要指定父类的
//
//		// 清理自己的
//		// delete ptr;
//
//		cout << "~Student()"<<endl;
//		// 为了保证析构时，保持先子再父的后进先出的顺序析构
//		// 子类析构函数完成后，会自动去调用父类的析构函数
//	}
//private:
//	int _id;
//};
//int main()
//{
//	Student s1("张三", 10);
//	Student s2(s1);
//	Student s3("李四",30);
//	s3 = s2;
//}


class Person
{
public:
 Person() { ++_count; }
protected:
 string _name; // 姓名
public:
 static int _count; // 统计人的个数。
};
int Person::_count = 0;
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};
void TestPerson()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << " 人数 :" << Person::_count << endl;
	Student::_count = 0;
	cout << " 人数 :" << Person::_count << endl;
}
