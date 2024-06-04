#include<iostream>
#include"Sort.h"
using namespace std;
int main() 
{
	Sort primul(7, 3, 20);
	primul.Print();
	cout << "\n";
	cout << primul.GetElementFromIndex(4) << " " << primul.GetElementsCount() << "\n";
	primul.InsertSort(false);
	primul.Print();
	cout << "\n";
	int vec[15],nr=0;
	for (int i = 7;i >= 3;i--)
		vec[++nr] = i;
	Sort aldoilea(vec, nr);
	aldoilea.BubbleSort(false);
	aldoilea.Print();
	cout << "\n";
	Sort ultim(5, 1, 8, 9, 6, 2);
	ultim.QuickSort(false);
	ultim.Print();
	return 0;


}