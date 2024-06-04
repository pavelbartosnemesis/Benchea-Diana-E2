#include <iostream>
#include <cstdarg>
#include "Sort.h"
using namespace std;
Sort::Sort(int nr, int mini, int maxi)
{
    n = nr;
    for (int i = 1; i <= nr; i++)
    {
        lista[i] = mini + (rand() % (maxi-mini));
    }
}

Sort::Sort(int list)
{
    /*int nr = 1;
    while (list->next != NULL)
    {
        lista[nr] = list->data;
        nr++;
    }*/
    //Nu cred ca e bine, nu stiu sa rezolv erorile
}

Sort::Sort(int vector[100], int nr)
{
    n = nr;
    for (int i = 1; i <= nr; i++)
    {
        lista[i] = vector[i];
    }
}

Sort::Sort(int nr, ...)
{
    va_list args;
    va_start(args, n);

    n = nr;
    int i = 1;

    while (n != 0)
    {
        lista[i] = va_arg(args, int);
        i++;
        n--;
    }
    va_end(args);
}

Sort::Sort(char string[100])
{
    n = 1;

    int nr = strlen(string);
    int nrCurent = 0;
    int i = 1;

    while (i <= nr)
    {
        if (string[i] != ',')
        {
            nrCurent = nrCurent * 10 + (int)(string[i] - '0');
        }
        else
        {
            lista[n] = nrCurent;
            n++;
            nrCurent = 0;
        }
        i++;
    }
}

void Sort::InsertSort(bool ascendent)
{
    int i, key, j;
    for (i = 2; i <= n; i++) {
        key = lista[i];
        j = i - 1;
        while (j >= 1 && lista[j] > key) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = key;
    }
    ascendent = true;
}

int partitie(int lista[], int l, int h)
{
    int x = lista[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (lista[j] <= x)
        {
            i++;
            int aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
    }
    int aux = lista[i + 1];
    lista[i + 1] = lista[h];
    lista[h] = aux;
    return (i + 1);
}

void Sort::QuickSort(bool ascendent )
{
    int l = 0;
    int h = n - 1;
    int stiva[100];
    int top = -1;

    stiva[++top] = l;
    stiva[++top] = h;

    while (top >= 0)
    {
        h = stiva[top--];
        l = stiva[top--];

        int p = partitie(lista, l, h);

        if (p - 1 > l)
        {
            stiva[++top] = l;
            stiva[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stiva[++top] = p + 1;
            stiva[++top] = h;
        }
    }
    ascendent = true;
}

void Sort::BubbleSort(bool ascendent )
{
    int ok = 0;
    while(!ok){
        ok = 1;
        for (int i = 1; i < n ; i++)
        {
            if (lista[i] > lista[i + 1])
            {
                ok = 0;
                int aux = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = aux;
            }
        }
    }
    ascendent = true;
}

void Sort::Print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << lista[i] << " ";
    }
}

int Sort::GetElementsCount()
{
    return n;
}

int Sort::GetElementFromIndex(int index)
{
    return lista[index];
}