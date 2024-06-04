#pragma once
#pragma warning(disable : 4996)
#include "Weather.h"
#include <cstring>

class Car {
private:
    char name[50];
    float FuelCapacity,FuelConsumption;
    int RainSpeed,SunnySpeed,SnowSpeed;
public:
    virtual void setname(const char* n) {
        strcpy(name, n);
    }
    void setFuel(int Capacity, int Consumption) {
        FuelCapacity = Capacity;
        FuelConsumption = Consumption;
    }
    void setSpeed(int r, int su, int sn) {
        RainSpeed = r;
        SunnySpeed = su;
        SnowSpeed = sn;
    }
    Car() {
        setname("Matiz");
        setFuel(60, 2);
        setSpeed(50, 50, 50);
    }
    const char* getName() const { return name; };
    int getFuelCapacity() const { return FuelCapacity; };
    int getFuelConsumption() const { return FuelConsumption; };
    int getRainSpeed() const { return RainSpeed; };
    int getSunnySpeed() const { return SunnySpeed; };
    int getSnowSpeed() const { return SnowSpeed; };
};