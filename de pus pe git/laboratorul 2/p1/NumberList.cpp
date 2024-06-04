#include "NumberList.h"
#include<iostream>
void NumberList::Init()
{
    count = 0;// count will be 0
}
bool NumberList::Add(int x)
{
    if (count >= 9)// if count is bigger or equal to 10, the function will return false
    {
        return false;
    }
    else// adds X to the numbers list and increase the data member count.
    {
        numbers[count] = x;
        count++;
    }
    return true;
}
void NumberList::Sort()// will sort the numbers vector
{
    int ok = 0;
    while (!ok)
    {
        ok = 1;
        for (int i = 0;i < count - 1;i++)
            if (numbers[i] > numbers[i + 1])
            {
                int aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
                ok = 0;
            }
    }
}
void NumberList::Print()// will print the current vector
{
    for (int i = 0;i < count;i++)
        printf("%d ", numbers[i]);
    printf("\n");
}