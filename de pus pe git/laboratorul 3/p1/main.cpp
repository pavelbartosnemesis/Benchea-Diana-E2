#include<iostream>
#include "Math.h"
using namespace std;
int main()
{
    Math calc;
    int a, b, c;
    double d, e, f;
    const char g = 'a', h = 'b';
    int count;
    cout << "Introduceti 3 numere intregi: ";
    cin >> a >> b >> c;
    cout << "\nSuma primelor 2 nr: " << calc.Add(a, b) << "\nSuma tuturor numerelor: " << calc.Add(a, b, c);
    cout << "\nInmultirea primelor 2 nr: " << calc.Mul(a, b) << "\nInmultirea tuturor numerelor: " << calc.Mul(a, b, c);

    cout << "\n\n\nIntroduceti 3 numere rationale: ";
    cin >> d >> e >> f;
    cout << "\nSuma primelor 2 nr: "<<calc.Add(d, e)<<"\nSuma tuturor numerelor: " << calc.Add(d, e, f) << endl;
    cout << "\nInmultirea primelor 2 nr: " << calc.Mul(d, e) << "\nInmultirea tuturor numerelor: " << calc.Mul(d, e, f);

    cout << "\n\n\nSuma literelor a si b: ";
    cout << calc.Add(g, h);

    cout << "\n\n\nSuma a 5 numere de la 1 la 5 :";
    cout << calc.Add(5, 1, 2, 3, 4, 5) << endl;
    return 0;

}