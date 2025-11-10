// 1. Write a program to implement following sorting techniques:
// a. Selection Sort
// b. Insertion Sort
// c. Bubble Sort
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped = false;
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[m])
                m = j;
        }
        swap(arr[i], arr[m]);
    }
}
  
void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main()
{
    int arr[] = {1, 3, 8, 4, 2, 7, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    selectionSort(arr, n);
    bubbleSort(arr, n);

    cout << "Sorted array = ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}