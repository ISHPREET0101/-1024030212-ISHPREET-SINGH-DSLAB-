#include <iostream>
using namespace std;

// Binary search to find position
int binarySearch(int arr[], int item, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void binaryInsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Find location using binary search
        int pos = binarySearch(arr, key, 0, j);

        // Shift elements to make space
        while (j >= pos)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[pos] = key;
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    binaryInsertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
