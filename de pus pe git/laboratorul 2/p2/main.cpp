#pragma warning(disable : 4996).
#include<iostream>
#include<cstring>
#include "Student.h"
#include "Compare.h"
using namespace std;
int main()
{
	char nume[100];
	Student student[2];
	float nota;
	cout << "Introduceti numele studentului 1:";
	cin >> nume;
	student[0].setname(nume);
	cout << "\nIntroduceti nota la matematica a studentului 1:";
	cin >> nota;
	student[0].setmath(nota);
	cout << "\nIntroduceti nota la engleza a studentului 1:";
	cin >> nota;
	student[0].seteng(nota);
	cout << "\nIntroduceti nota la istorie a studentului 1:";
	cin >> nota;
	student[0].sethis(nota);
	cout << "\n\n\nIntroduceti numele studentului 2:";
	cin >> nume;
	student[1].setname(nume);
	cout << "\nIntroduceti nota la matematica a studentului 2:";
	cin >> nota;
	student[1].setmath(nota);
	cout << "\nIntroduceti nota la engleza a studentului 2:";
	cin >> nota;
	student[1].seteng(nota);
	cout << "\nIntroduceti nota la istorie a studentului 2:";
	cin >> nota;
	student[1].sethis(nota);
	int catalog = (CompareName(student));
	if (catalog == 0)
		cout << "\nAmbii studenti au acelasi nume.";
	if (catalog == 1)
		cout << "\nStudentul " << student[1].getname() << " apare primul in catalog.";
	if (catalog == -1)
		cout << "\nStudentul " << student[0].getname() << " apare primul in catalog.";
	int catalogmate = (CompareMathGrades(student));
	if (catalogmate == 0)
		cout << "\nAmbii studenti au aceeasi nota la matematica.";
	if (catalogmate == 1)
		cout << "\nStudentul " << student[0].getname() << " are nota mai mare la matematica.";
	if (catalogmate == -1)
		cout << "\nStudentul " << student[1].getname() << " apare primul in catalog.";
	int catalogeng = (CompareEngGrades(student));
	if (catalogeng == 0)
		cout << "\nAmbii studenti au aceeasi nota la engleza.";
	if (catalogeng == 1)
		cout << "\nStudentul " << student[0].getname() << " are nota mai mare la engleza.";
	if (catalogeng == -1)
		cout << "\nStudentul " << student[1].getname() << " are nota mai mare la engleza.";
	int catalogist = (CompareHisGrades(student));
	if (catalogist == 0)
		cout << "\nAmbii studenti au aceeasi nota la istorie.";
	if (catalogist == 1)
		cout << "\nStudentul " << student[0].getname() << " are nota mai mare la istorie.";
	if (catalogist == -1)
		cout << "\nStudentul " << student[1].getname() << " are nota mai mare la istorie.";
	int catalogmed = (CompareAvg(student));
	if (catalogmed == 0)
		cout << "\nAmbii studenti au aceeasi medie.";
	if (catalogmed == 1)
		cout << "\nStudentul " << student[0].getname() << " are media mai mare.";
	if (catalogmed == -1)
		cout << "\nStudentul " << student[1].getname() << " are media mai mare.";
	return 0;
}