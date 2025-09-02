// 5) Given a fixed-length integer array arr, duplicate each occurrence of two (2), 
// shifting the remaining elements to the right.  Note that elements beyond the length of the original 
// array are not written. Do the above modifications to the input array in place and do not return 
// anything. 
#include <iostream>
using namespace std;

void duplicateTwos(int arr[],int n){
    int count2 = 0;
  
    for(int i=0;i<n;i++) {
        if(arr[i] == 2) {
            count2++;
        }
    }
    
    int i = n-1;              
    int j = n +count2-1; 
   
    while(i < j) {
        if(arr[i] == 2) {
            if(j < n) arr[j] = 2;  
            j--;
            if(j < n) arr[j] = 2; 
            j--;
        } else {
            if(j < n) arr[j] = arr[i];
            j--;
        }
        i--;
    }
    
}


int main() {
    int arr[] ={1,3,2,2,4,5,2,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array = " << endl;

     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    duplicateTwos(arr, n);

    cout << "Modified Array = " << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
