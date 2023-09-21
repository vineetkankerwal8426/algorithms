#include <iostream>
using namespace std;

void selecionSort(int arr[], int size)
{
    int i, j, minInd;
    for (i = 0; i < size - 1; i++)
    {
        minInd = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
        }
        if (minInd != i)
        {
            swap(arr[minInd], arr[i]);
        }
    }
}

// recursive approach using max element

void selectionSort(int arr[], int size, int j, int max) //max and j will be initially zero i.e max =0;j =0;
{
    if (size == 1)
    {
        return;
    }
    if (j < size)
    {
        if (arr[j] > arr[max])
        {
            // max = j;
            selectionSort(arr, size, j + 1, j);
        }
        else
        {
            selectionSort(arr, size, j + 1, max);
        }
    }
    else
    {
        swap(arr[j - 1], arr[max]);
        selectionSort(arr, size - 1, 0, 0);
    }
}
