#include<iostream>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas tablou(50,50);
	tablou.Clear();
	tablou.DrawRect(10,10,30,30,'*');
	tablou.Print();
	tablou.FillRect(10, 10, 30, 30, '*');
	tablou.Print();
	tablou.SetPoint(15, 15, '0');
	tablou.Print();
	tablou.Clear();
	tablou.DrawCircle(10, 10, 5, '@');
	tablou.Print();
	tablou.FillCircle(10, 10, 5, '@');
	tablou.Print();

	return 0;
}