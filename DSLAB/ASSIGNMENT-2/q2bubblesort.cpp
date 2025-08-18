/*2) Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping
the adjacent elements if they are in wrong order. Code the Bubble sort with the
following elements:
*/
#include<iostream>
using namespace std;

void bubbleSort(int arr[],int& size){
    int i,j,temp;
for(i=0;i<size-1;i++){
for(j=0;j=size-i-1;j++){
    if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        }
    }
}
}

int main(){
    int i;
    int arr[] = {64,34,25,12,22,11,90};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,size);
    
    cout << "Sorted arr" << endl ;
    for(i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}