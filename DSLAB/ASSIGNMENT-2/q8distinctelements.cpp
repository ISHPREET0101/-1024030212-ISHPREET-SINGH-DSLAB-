// 8) Write a program to count the total number of distinct elements in an array of length n. 
#include <iostream>
using namespace std;

int distinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of element = ";
    cin >> n;

    int arr[n];
    cout << "Enter elements = ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Total distinct elements = " << distinct(arr, n) << endl;

    return 0;
}
