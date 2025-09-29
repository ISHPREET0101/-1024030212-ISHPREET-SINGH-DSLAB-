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

void optBubbleSort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
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
  
void impSelectionSort(int arr[], int n){
    for(int i=0;i<n/2;i++){
        int min = i;
        int max = i;

        for(int j=i;j<n-i;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
            if(arr[j] > arr[max]){
                max = j;
            }
        }

        swap(arr[i],arr[min]);

        if(max == i){
            max = min;
        }

        swap(arr[n-i-1],arr[max]);
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

    // insertionSort(arr, n);
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    impSelectionSort(arr,n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}