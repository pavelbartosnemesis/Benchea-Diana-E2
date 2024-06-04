#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE //fara astea 3 linii nu merge scanf :(
#include<fstream>
#include<stdio.h>
using namespace std;
int main()
{
    char* cuv, ordinecuv[100][100], propozitie[100];
    scanf("%[^\n]", propozitie);
    cuv = strtok(propozitie, " ");
    int k = 1;
    while (cuv)
    {
        strcpy(ordinecuv[k], cuv);
        cuv = strtok(NULL, " ");
        k++;
    }
    k--;
    int ok = 0;
    while (!ok)
    {
        ok = 1;
        for (int i = 1;i < k;i++)
            if (strlen(ordinecuv[i]) < strlen(ordinecuv[i + 1]))
            {
                swap(ordinecuv[i], ordinecuv[i + 1]);
                ok = 0;
            }
     }
    for (int i = 1;i <= k;i++)
        printf("%s \n", ordinecuv[i]);
    return 0;
}