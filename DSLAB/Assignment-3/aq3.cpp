// 3. Given an array arr[ ] of integers, the task is to find the Next Greater Element 
// for each element of the array in order of their appearance in the array. Note:
//  The Next Greater Element for an element x is the first greater element on the right 
//  side of x in the array. Elements for which no greater element exist, consider the next 
//  greater element as -1.  

#include<iostream>
#include<vector>
using namespace std;

vector<int>large(vector<int>&arr){
    int n =arr.size();
    vector<int>arr1(n,-1);
    for(int i=0;i<n;i++){
        for (int j=i + 1; j<n;j++) {
            if (arr[j] > arr[i]) {
                arr1[i] = arr[j];
                break;
            }
    }
    }
    return arr1;
}


int main() {

    vector<int>arr ={5,6,3,8,9};
    vector<int>arr1 =large(arr);
    for (int i=0;i<arr1.size();i++) {
        cout << arr1[I] << " ";
    }

    return 0;
}

