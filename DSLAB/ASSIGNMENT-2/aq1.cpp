// 1) Find two numbers in an array whose difference equals K. Given an array arr[] and
//  a positive integer k, the task is to count all pairs (i, j) such
//  that i < j and absolute value of (arr[i] - arr[j]) is equal to k. 

#include<iostream>
using namespace std;

int difference(int arr[],int k, int n){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(arr[i] - arr[j]) == k){
                count++;
            }
        }
    }
    cout << count;
    return count;
}

int main(){
    int n,k;
    cout << "Enter the size of array" << endl;
    cin >> n;
    
    int* arr = new int[n]; 
    
    for(int i=0;i<n;i++){
        cout << "Enter array element  " << i +1 << "=" ; 
        cin >> arr[i];
    }

    cout << "Array elements are = " <<endl;
    for(int i=0;i<n;i++){
        cout << "Element [" << i << "]" << arr[i] <<endl;
    }
    cout << "Enter the difference = ";
    cin >> k;

    difference(arr,k,n);
    delete[] arr;
}