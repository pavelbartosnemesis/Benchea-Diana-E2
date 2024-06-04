#pragma once
class Number
{
	int baza;
	char* numar;
public:
	Number(const char* value, int base);
	~Number();
	Number(Number& n); //constructor de copiere
	Number(const Number& n);//constructor de mutare
	Number(const char* s);
	Number(int x);
	Number()
	{
		numar = nullptr;
		baza = 0;
	}
	friend Number operator + (Number& n1, Number& n2);
	friend Number operator - (Number& n1, Number& n2);
	char* operator += (Number& n);
	char* operator = (int n);
	char operator [](int i);
	bool operator < (Number& n);
	bool operator > (Number& n);
	bool operator >= (Number& n);
	bool operator <= (Number& n);
	bool operator == (Number& n);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount();
	int  GetBase();
};