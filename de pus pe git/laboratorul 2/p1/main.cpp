#include<iostream>
#include "NumberList.h"
using namespace std;
int main()
{
	printf(" Introduceti o lungime de vector mai mica de 10 :");
	int n;
	cin >> n;
	NumberList vector;
	printf("\n Introduceti %d numere pentru vector : ", n);
	vector.Init();
	for (int i = 1;i <= n;i++)
	{
		int numar;
		cin >> numar;
		vector.Add(numar);

	}
	printf("\n Acesta este vectorul dumneavoastra, sortat : ");
	vector.Sort();
	vector.Print();
	return 0;

		
}