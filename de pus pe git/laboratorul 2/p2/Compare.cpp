#include "Compare.h"
#include<cstring>
int CompareName(Student student[2])
{
	if (strcmp(student[0].getname(), student[1].getname()) == 0)
		return 0;
	else
		if (strcmp(student[0].getname(), student[1].getname()) < 0)
			return -1;
	return 1;
}

int CompareMathGrades(Student student[2])
{
	if (student[0].getmath() < student[1].getmath())
		return -1;
	if (student[0].getmath() == student[1].getmath())
		return 0;
	return 1;
}

int CompareEngGrades(Student student[2])
{
	if (student[0].geteng() < student[1].geteng())
		return -1;
	if (student[0].geteng() == student[1].geteng())
		return 0;
	return 1;
}

int CompareHisGrades(Student student[2])
{
	if (student[0].gethis() < student[1].gethis())
		return -1;
	if (student[0].gethis() == student[1].gethis())
		return 0;
	return 1;
}

int CompareAvg(Student student[2])
{
	if (student[0].getgrade() < student[1].getgrade())
		return -1;
	if (student[0].getgrade() == student[1].getgrade())
		return 0;
	return 1;
}