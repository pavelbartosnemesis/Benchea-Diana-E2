#include <iostream>
using namespace std;
class Kelvin {
public:
    Kelvin(long double kelvin) : nr(kelvin) {}
    operator float() const {
        return static_cast<float>(nr - 273.15);
    }

private:
    long double nr;
};

class Fahrenheit {
public:
    Fahrenheit(long double fahrenheit) : nr(fahrenheit) {}
    operator float() const {
        return static_cast<float>((nr - 32)/1.8);
    }

private:
    long double nr;
};

Kelvin operator"" _Kelvin(unsigned long long nr) {
    return Kelvin(static_cast<long double>(nr));
}

Fahrenheit operator"" _Fahrenheit(unsigned long long nr) {
    return Fahrenheit(static_cast<long double>(nr));
}
int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
    cout << a << b;
	return 0;
}