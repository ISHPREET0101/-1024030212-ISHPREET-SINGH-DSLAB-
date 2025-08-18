// 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said 
// to be an inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ].
//  Write a program to count the number of inversions in an array.
#include<iostream>
using namespace std;

int inversion(int arr[],int n){
    int count =0;
    for(int i=0;i<n ;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                count++;
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            }
        }
    }
    return count;
}
int main(){
    int arr[] = {1,4,6,3,2,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Number of inversion = " << inversion(arr,n);
    return 0;
}