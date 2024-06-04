#pragma once
class Student
{
	char nume[100];
	float medie, mate, eng, ist;
public:
	void setname(char name[100]);
	char* getname();
	void setmath(float nota);
	float getmath();
	void seteng(float nota);
	float geteng();
	void sethis(float nota);
	float gethis();
	float getgrade();
};

