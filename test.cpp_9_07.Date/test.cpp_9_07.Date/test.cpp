#include"Date.h"

void Test1()
{
	Date d2(2021, 2, 22);
	d2.Print();
	d2 += 122;
	d2.Print();
}
void Test2()
{
	Date d2(2021, 2, 22);
	d2.Print();
	Date d4 = d2+ 23;
	d4.Print();
	Date d3 = d2-23;
	d3.Print();
}
void Test3()
{
	Date d2(2021, 2, 22);
	d2.Print();
	Date d4 = d2 + 23;
	d4.Print();
	if (d2 < d4)
	{
		cout << "第一个小于第二个" << endl;
	}
}
void Test4()
{
	Date d2(2021, 2, 22);
	Date d3(++d2);
	d2.Print();
	d3.Print();
}
int main()
{;
	//Test1();
	//Test2();
	//Test3();
	Test4();


	return 0;
}