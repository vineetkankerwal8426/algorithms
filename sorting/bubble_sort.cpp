#include <iostream>
using namespace std;

void bubble(int arr[], int size)
{
    bool _swap = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                _swap = true;
            }
        }
        if (!_swap)
            return;
        _swap = 0;
    }
}

// recursive approach

void bubble(int arr[], int size, int j) //j will be initially zero i.e j =0;
{
    if (size == 1)
        return;
    if (j < size - 1)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            bubble(arr, size, j + 1);
        }
    }
    else
    {
        bubble(arr, size - 1, 0);
    }
}
