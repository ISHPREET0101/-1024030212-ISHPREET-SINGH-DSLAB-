// ! 1) Implement the Binary search algorithm regarded as a fast search algorithm with run-time complexity of Ο(log n) in comparison to the Linear Search. 
#include<iostream>
using namespace std;

int binarySearch(int arr[],int& val,int n){
    int mid, low = 0;
    int high = n-1;
    int i;
    while(low <= high){
    
        mid = (high + low)/2;

        if(arr[mid] > val){
            high = mid - 1;
        }else if(arr[mid] < val){
            low = mid + 1;
        }
        else if(arr[mid] == val){
        cout << "Value found at position " << mid + 1 << endl;
        break;
        }
        else {
            cout << "No element found";
        }
    }
    return 0;
}
int main(){
    int value;
    int arr[] = {2,3,5,6,7,8,12,14,54,65,76,87};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Enter the value you want to find";
    cin >> value;
    binarySearch(arr,value,n);
    return 0;
}