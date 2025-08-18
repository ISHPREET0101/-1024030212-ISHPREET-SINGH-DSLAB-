// (d) Write a program to sort the strings in alphabetical order. 
#include<iostream>
#include<string>
using namespace std;
void input(string*& arr,int size){    
    arr = new string[size];
    for( int i=0;i<size;i++){
        cout << "Enter string " << i+1 << " = ";
        cin >> arr[i];
    }
}
void sortString(string *arr,int size){
    for(int i=0;i<size;i++){
        for(int j=i +1;j<size;j++){
            if(arr[i] > arr[j]){
                string c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;
            }
        }
    }
    cout << "Sorted string's = ";
    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int size;
    string* arr = nullptr;
     cout << "Enter the number of strings = " << endl;
    cin >> size;
    input(arr,size);
    sortString(arr,size);
    return 0;
}