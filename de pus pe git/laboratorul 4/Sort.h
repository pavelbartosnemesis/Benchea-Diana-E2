#pragma once
class Sort
{
    int n, lista[100];
    // add data members
public:
    Sort(int nr,int mini,int maxi);
    Sort(int list);
    Sort(int vector[100], int nr);
    Sort(int nr, ...);
    Sort(char string[100]);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
