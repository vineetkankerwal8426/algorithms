// use when array have value in range(m,n) 
// in this case array have value in range(1,n) {5,4,3,2,1} after sort - {1,2,3,4,5} range is in 1 to 5. Time complexity is O(n)


#include<iostream>
using namespace std;

void cyclicSort(int arr[],int size){
    int i =0;
    while(i<size){
        int correct = arr[i] -1;
        if(arr[i]!= arr[correct]){
            swap(arr[i],arr[correct]);
        }
        else{
            i++;
        }
    }
}

//or


void cyclicSort(int arr[],int size){
    for(int i =0;i<size;){
        if(arr[i]!=arr[arr[i]-1]){
            swap(arr[i],arr[arr[i]-1]);
        }
        else i++;
    }
}