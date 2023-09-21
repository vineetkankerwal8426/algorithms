// recursive binary search for rotated array
// rotated array means arr = {7,8,9,10,1,2,3,4,5,6} i.e arr is rotated from 7;

int binarySearch(int arr[], int target, int s, int e)
{
    if (s > e)
        return -1;
    int m = s + (e - s) / 2;
    if (arr[m] == target)
        return m;
    else if (arr[s] <= arr[m])
    {
        if (target >= arr[s] && target <= arr[m])
            return binarySearch(arr, target, s, m - 1);
        else
            return binarySearch(arr, target, m + 1, e);
    }
    else
    {
        if (target >= arr[m] && target <= arr[e])
            return binarySearch(arr, target, m + 1, e);
        else
        {
            return binarySearch(arr, target, s, m - 1);
        }
    }
}