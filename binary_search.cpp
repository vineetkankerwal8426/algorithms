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

