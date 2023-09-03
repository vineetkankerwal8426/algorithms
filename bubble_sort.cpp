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
        if (!_swap) return;
        _swap = 0;
    }
}

