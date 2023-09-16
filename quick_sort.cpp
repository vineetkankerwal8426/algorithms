#include<iostream>
using namespace std;

void quickSort(int arr[],int low ,int high){
    if(low>=high){
        return;
    }
    int s = low ;
    int e = high;
    int mid = low+(high-low)/2;
    int pivot = arr[mid];
    while(s<=e){
        while(arr[s]<pivot){
            s++;
        }
        while(arr[e]>pivot){
            e--;
        }
        if(s<=e){
            swap(arr[s],arr[e]);
            s++;e--;
        }
    }
    quickSort(arr,low,e);
    quickSort(arr,s,high);
    
}