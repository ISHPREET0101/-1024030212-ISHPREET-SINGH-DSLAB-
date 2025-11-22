// 6. Implement priority queues using heaps.
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

void insert(int arr[],int key,int n){
        arr[n] = key;
        int i = n;
        n++;

        while (i > 0 && arr[(i - 1) / 2] < arr[i]){
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int getMax(int arr[],int n){
        if (n == 0) {
            cout << "Priority Queue is empty\n";
            return -1;
        }
        return arr[0];
    }

    int extractMax(int arr[],int n){
        if (n == 0) {
            cout << "Priority Queue Underflow" << endl;
            return -1;
        }

        int maxItem = arr[0];
        arr[0] = arr[n - 1];
        n--;

        maxHeapify(arr,n,0);

        return maxItem;
    }


void heapIncreaseKey(int arr[],int i,int key){
        if(key < arr[i]){
            cout << "New key is smaller than the current key" << endl;
            return;
        }

        arr[i] = key;

        while(i>0 && arr[(i-1)/2] < arr[i]){
            swap(arr[i],arr[(i-1)/2]);
            i = (i-1)/2;
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
    return 0;
}