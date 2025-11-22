// 5. Implement Heapsort (Increasing/Decreasing order).
#include<iostream>
#include<climits>
using namespace std;

void maxHeapify(int arr[],int n,int i){
    int large = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l < n && arr[l] > arr[large]){
        large = l;
    }
    
    if(r < n && arr[r] > arr[large]){
        large = r;
    }

    if(large != i){
        swap(arr[i],arr[large]);
        maxHeapify(arr,n,large);
    }
}

void buildMaxHeap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1;i>=1;i--){
        maxHeapify(arr,n,i);
    }

    for(int i=n-1;i>=1;i--){
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
}


int main(){
    int arr[] = {3,5,9,6,8,20,10,12,18,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    buildMaxHeap(arr,n);
    cout << "Max Head = ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}