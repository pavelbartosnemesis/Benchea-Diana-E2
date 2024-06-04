#include "Circuit.h"
#include "Car.h"
#include "BMW.h"
#include"Fiat.h"
#include"RangeRover.h"
#include"Seat.h"
#include"Volvo.h"
#include <iostream>
using namespace std;
void Circuit::SetLength(int nr) {
	lungime = nr;
}
void Circuit::SetWeather(Weather prezent) {
	vreme = prezent;
}
int Circuit::getspeed(Car masina){
	if (vreme == Weather::Rain)
		return masina.getRainSpeed();
	if (vreme == Weather::Sunny)
		return masina.getSunnySpeed();
	if (vreme == Weather::Snow)
		return masina.getSnowSpeed();
}
void Circuit::AddCar(Car* racer) {
	masini[++concurenti].setname(racer->getName());
}
void Circuit::Race() {
	castigatori = concurenti;
	int ok = 0;
	while (!ok) {
		ok = 1;
		for (int i = 1;i <= concurenti;i++)
			if (getspeed(masini[i]) < getspeed(masini[i + 1]))
			{
				Car aux;
				aux.setname(masini[i].getName());
				masini[i].setname(masini[i+1].getName());
				masini[i+1].setname(aux.getName());
				ok = 0;
			}
	}
	
	for (int i = 1;i <= castigatori;i++)
		if (lungime > (masini[i].getFuelCapacity() / masini[i].getFuelConsumption()))
		{
			pierzatori++;
			neajunsi[pierzatori].setname(masini[i].getName());
			for (int i = 1;i <= castigatori;i++)
				masini[i].setname(masini[i + 1].getName());
			castigatori--;

		}
}
void Circuit::ShowFinalRanks() {
	for (int i = 1;i <= castigatori;i++)
		cout << masini[i].getName() << "(" << lungime / getspeed(masini[i]) << ") ";
	cout << "\n";
}
void Circuit::ShowWhoDidNotFinish() {

	for (int i = 1;i <= pierzatori;i++)
		cout << masini[i].getName() << " ";
	cout << "\n";
}
