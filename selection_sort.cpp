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
