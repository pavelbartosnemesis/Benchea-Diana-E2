#include<fstream>
#include<stdio.h>

int convertire(const char *numar)
{
	int convertit = 0;
	while (isdigit(*numar))
	{
		convertit = convertit * 10 + (*numar - '0');
		numar++;
	}
	return convertit;
}
int main()
{
	FILE *in=fopen("in.txt", "r");
	char cuvant[100];
	int suma = 0;
	while (fgets(cuvant, sizeof(cuvant), in)) 
		{
		char *point = cuvant;
		suma += convertire(point);
		}
	printf("Suma este: %d\n", suma);
	fclose(in);
	return 0;
}