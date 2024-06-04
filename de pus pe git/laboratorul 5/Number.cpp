#include <iostream>
#include<cstring>
#include "Number.h"

using namespace std;

Number::Number(const char* value, int base)
{
    baza = base;
    strcpy(numar, value);
}
Number::~Number()
{
    delete numar;
    numar = nullptr;
}

Number::Number(const Number& n)
{
    baza = n.baza;
    int nr = strlen(n.numar) + 1;
    numar = new char(nr);
    memcpy(numar, n.numar, nr);
}
Number::Number(Number& n) 
{
    baza = n.baza;
    numar = nullptr;
    numar = n.numar;
}
Number::Number(const char* s)
{
    baza = 10;
    strcpy(numar, s);
    int nr;
    for (int i = 0;i < strlen(s);i++)
        nr = nr * 10 + (int)(s[i]-'0');

}
Number::Number(int x)
{
    baza = 10;
    char n[100];
    int i = 0;
    if (x == 0)
    {
        n[0] = '0';
        n[1] = '\0';
    }
    while (x) {
        {n[i] = (char)x % 10;
        x /= 10;
        }
    }
    strrev(n);
    strcpy(numar, n);
   
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
char reVal(int num)
{
    if (num <= 0 && num >= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
void reverse_char(char* val1)
{
    int len = strlen(val1);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = val1[i];
        val1[i] = val1[len - i - 1];
        val1[len - i - 1] = temp;
    }
}
int inBaza10(char* numar, int baza)
{
    char val1[100];
    val1[0] = '\0';
    strcpy(val1, numar);

    //Conversie din baza curenta in baza 10

    int length = strlen(val1);
    int power = 1; // Initializare putere baza
    int num = 0;  // Numarul in baza 10

    for (int i = length - 1; i >= 0; i--)
    {
        num += val(val1[i]) * power;
        power = power * baza;
    }

    return num;
}
char* dinBaza10(int num, int baza)
{
    int p = 1, rest, index = 0;
    char aux[100];
    aux[0] = '\0';
    while (num != 0)
    {
        rest = num % baza;
        num /= baza;
        if (rest <= 9)
        {
            aux[index] = (char)(rest + '0');
        }
        else
        {
            aux[index] = (char)(rest % 10 + 'A');
        }
        index++;
        p *= 10;
    }
    aux[index] = '\0';
    reverse_char(aux);
    return aux;
}

Number operator + (Number& n1, Number& n2)
{
    Number suma;
    if (n1.baza < n2.baza)
    {
        suma.baza = n2.baza;
    }
    else
    {
        suma.baza = n1.baza;
    }

    int num1 = inBaza10(n1.numar, n1.baza);
    int num2 = inBaza10(n2.numar, n2.baza);
    int sum10 = num1 + num2;

    suma.numar = dinBaza10(sum10, n1.baza);
    return suma;
}
Number operator - (Number& n1, Number& n2)
{
    Number dif;
    if (n1.baza < n2.baza)
    {
        dif.baza = n2.baza;
    }
    else
    {
        dif.baza = n1.baza;
    }

    int num1 = inBaza10(n1.numar, n1.baza);
    int num2 = inBaza10(n2.numar, n2.baza);
    int dif10 = num1 - num2;

    dif.numar = dinBaza10(dif10, n1.baza);
    return dif.numar;
}
char* Number::operator += (Number& n)
{
    int num1 = inBaza10(numar, baza);
    int num2 = inBaza10(n.numar, n.baza);
    num1 += num2;

    if (baza < n.baza)
    {
        baza = n.baza;
    }
    numar = dinBaza10(num1, baza);

    return numar;
}
char* Number::operator = (int n)
{
    baza = 10;
    numar = dinBaza10(n, 10);
    return numar;
}
char Number::operator [] (int i)
{
    return numar[i];
}
bool Number::operator < (Number& n)
{
    int num1 = inBaza10(numar, baza);
    int num2 = inBaza10(n.numar, n.baza);

    return num1 < num2;
}
bool Number::operator > (Number& n)
{
    int num1 = inBaza10(numar, baza);
    int num2 = inBaza10(n.numar, n.baza);

    return num1 > num2;
}
bool Number::operator >= (Number& n)
{
    int num1 = inBaza10(numar, baza);
    int num2 = inBaza10(n.numar, n.baza);

    return num1 >= num2;
}
bool Number::operator <= (Number& n)
{
    int num1 = inBaza10(numar, baza);
    int num2 = inBaza10(n.numar, n.baza);

    return num1 <= num2;
}
bool Number::operator == (Number& n)
{
    int num1 = inBaza10(numar, baza);
    int num2 = inBaza10(n.numar, n.baza);

    return num1 == num2;
}

void Number::SwitchBase(int newBase)
{
    int num1 = inBaza10(numar, baza);
    numar = dinBaza10(num1, newBase);
}
void Number::Print()
{
    cout << numar << endl;
}
int Number::GetDigitsCount()
{
    return strlen(numar);
}
int Number::GetBase()
{
    return baza;
}