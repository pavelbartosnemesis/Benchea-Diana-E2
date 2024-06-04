#pragma once
#include "Car.h"
#include "BMW.h"
#include"Fiat.h"
#include"RangeRover.h"
#include"Seat.h"
#include"Volvo.h"
#include "Weather.h"
class Circuit
{
	int lungime,concurenti=0,castigatori=0,pierzatori=0;
	Weather vreme;
	Car masini[100],neajunsi[100];
public:
	void SetLength(int nr);
	void SetWeather(Weather prezent);
	virtual void AddCar(Car* racer);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	int getspeed(Car masina);
};

