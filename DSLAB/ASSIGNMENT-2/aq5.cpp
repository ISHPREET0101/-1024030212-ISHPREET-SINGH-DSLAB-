// 5) Given a fixed-length integer array arr, duplicate each occurrence of two (2), 
// shifting the remaining elements to the right.  Note that elements beyond the length of the original 
// array are not written. Do the above modifications to the input array in place and do not return 
//
// anything. 
#include <iostream>
#include <vector>
using namespace std;

void duplicate2s(vector<int>& arr) {
    int n = arr.size();
    int twos = 0;

    for (int x : arr) {
        if (x == 2) twos++;
    }

    int i = n - 1;        
    int j = n + twos - 1; 

    while (i >= 0 && j >= 0) {
        if (arr[i] == 2) {
            if (j < n) arr[j] = 2;
            j--;
            if (j < n) arr[j] = 2;
            j--;
        } else {
            if (j < n) arr[j] = arr[i];
            j--;
        }
        i--;
    }
}

int main() {
    vector<int> arr = {1,2,3,2,4,5};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    duplicate2s(arr);
    cout << "Modified array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
