//4)  Sort an array of 0s, 1s and 2s - Dutch National Flag Problem Given an array arr[] consisting of only 0s, 1s, and 2s.
//   The objective is to sort the array, i.e., put all 0s first, then all 1s and all 2s in last. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sorting(int* arr,int n){
    sort(arr,arr+n);
}

int main(){
    int n;
    cout << "Enter the number of elements in an array = " <<endl;
    cin >> n;
    int* arr = new int[n];

    cout << "Enter elements = " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sorting(arr, n);

    cout << "Sorted array = ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}