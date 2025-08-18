// 3) Design the Logic to Find a Missing Number in a Sorted Array. 
// Given an array of n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted Array 
// (a) Linear time 

#include<iostream>
using namespace std;

int missingnumber(int arr[], int n){
    for(int i = 0 ; i<n ; i++){
        if(arr[i] != i+1){
            arr[i] = i + 1;
            cout << "Missing number is = " << i + 1;
            break;
        }
    }
    return 0;
}

int main(){
    int arr[] = {1,2,3,4,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    missingnumber(arr,n);
    return 0;
}