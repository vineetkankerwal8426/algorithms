#include<iostream>
using namespace std;


void merge(int arr[],int s,int e){
    int mid = s+(e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    
    int * left = new int[len1];
    int * right = new int[len2];
    
    for(int i =0;i<len1;i++){
        left[i] = arr[s+i];
    }
   
    for(int i =0;i<len2;i++){
        right[i] = arr[mid+1+i];
    }
    int i =0;
    int j =0;
    int k = s;
    while(i<len1 && j<len2){
        if(left[i]<right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i<len1){
        arr[k++] = left[i++];
    }
    while(j<len2){
        arr[k++]=right[j++];
    }
    delete[] right;
    delete[] left;
}



void mergeSort(int arr[], int s ,int e){
    if(s>=e) return;
    int m = s+(e-s)/2;
    mergeSort(arr,s,m);
    mergeSort(arr,m+1,e);
    merge(arr,s,e);
}