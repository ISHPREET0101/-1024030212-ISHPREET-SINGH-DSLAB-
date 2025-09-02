//4)  Sort an array of 0s, 1s and 2s - Dutch National Flag Problem Given an array arr[] consisting of only 0s, 1s, and 2s.
//   The objective is to sort the array, i.e., put all 0s first, then all 1s and all 2s in last. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort(int arr[],int n){
    int l = 0, m = 0, h = n - 1;

    while(m <= h) {
        if(arr[m] == 0) {
            swap(arr[l], arr[m]);
            l++;
            m++;
        }else if(arr[m] == 1) {
            m++;
        }else{ 
            swap(arr[m], arr[h]);
            h--;
        }
    }
}

void sorting(vector<int> &arr){
    sort(arr.begin(), arr.end());
}
int main() {
    vector<int> arr ={0,1,2,2,1,0,0,2,0,1};
    int array[] ={0,1,2,2,1,0,0,2,0,1};
    int n = 10;
    sorting(arr);
    
    sort(array,n);

    for (int i=0; i<arr.size();i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    for (int i=0; i<10;i++){
        cout << array[i] << " ";
    }
    return 0;
}

