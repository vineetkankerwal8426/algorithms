#include<iostream>
using namespace std;

int binary(int arr[],int target,int size){
    int start =0;
    int end = size-1;
    
    bool isAsc = arr[start]<arr[end];
    while(start<= end){
        int mid = start+(end-start)/2;
        if (arr[mid]==target){
            return mid;
        }

        else if (isAsc){
            if(arr[mid] > target){
                end = mid -1;
            }
            else if(arr[mid]<target){
                start= mid+1;
            }
        }
        else {
            if (arr[mid]>target){
                start = mid +1;
            }
            else if (arr[mid]<target){
                end = mid -1;
            }
        }
    }
    return -1;
}



//RECURSIVE METHOD

int binary(int arr[], int start, int end, int target)
{   
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binary(arr, mid + 1, end, target);
    else
        return binary(arr, start, mid - 1, target);
}

