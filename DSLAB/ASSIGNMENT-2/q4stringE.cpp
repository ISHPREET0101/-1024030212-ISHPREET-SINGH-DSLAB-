// (e) Write a program to convert a character from uppercase to lowercase. 
#include<iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    char arr[size] = {};
    
    cout << "Enter the elements of the array" << endl;

    for(int i=0;i<size;i++){
        cout << "Enter the element " << i +1 << " = " << endl;
        cin >> arr[i] ;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 'A' && arr[i] <= 'Z') {
            arr[i] = arr[i] + 32;  
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}