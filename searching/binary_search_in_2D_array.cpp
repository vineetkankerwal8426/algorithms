#include <iostream>
#include <vector>
using namespace std;

// for the array that is not strictly sorted. Example :
// {
// {10,20,30,40},
// {15,25,35,45},
// {28,29,37,49},
// {33,34,38,50}
// }

vector<int> search(vector<vector<int>> &arr, int target)
{
    int row = 0;
    int col = arr[0].size() - 1;
    while (row < arr.size() && col >= 0)
    {
        if (arr[row][col] == target)
        {
            return {row, col};
        }
        else if (arr[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    return {-1, -1};
}
