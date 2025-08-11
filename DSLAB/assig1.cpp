# include <iostream>
using namespace std; 
#include<string>
// int revNum(int a , int b){
//     int c;
//     cin >> a >> b;
//     c = a;
//     a = b;
//     b = c;
//     cout << a <<" "<<b;
    
//     return 0;

// }

// int main(){
//     int n,m;
//     revNum(n,m);

// }

//assignment 1 
//ques3
// int main()
// {
// int i;
// int arr[5] = {1};
// for (i = 0; i < 5; i++)
// printf("%d",arr[i]);
// return 0;
// }


// Reverse the elements of an array

// int revNum(int arr[], int n) {

// 	for(int i=0;i<n;i++){
// 	int temp = arr[i];
// 	arr[i] = arr [n-1-i];
// 	arr [n-1-i] = temp;
//     }
// 	return 0;
// }

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
// 	cin >> arr[i];
//     }
//     revNum(arr ,n);
//     for (int i = 0; i <n; i++)
//     {
//         cout << arr[i]<<endl;
//     }

//     return 0;
// }

// 1) Developa Menu driven program to demonstrate the following operations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT

#include<string>
//gpt
// void menu(){
//     int choice;
//     int n;
//     cout << "How many strings ";
//     cin >> n;
//     cin.ignore();
//     string* arr = new string[n];
    
//     cin >> choice;
//     do{
//         cout << "Menu";
//     cout << "1.CREATE";
//     cout << "2.DISPLAY";
//     cout << "3.INSERT";
//     cout << "4.DELETE";
//     cout << "5.LINEAR SEARCH";
//     cout << "6.EXIT";
//     cout << "Enter choice";

//     switch(choice){
//         case 1:
//         for (int i = 0; i < n; i++) {
//         cout << "Enter string " << i+1 << ": ";
//         getline(cin, arr[i]);
//         break;
//     }

//         case 2:
//         cout << "You entered:\n";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << endl;
//     }
//     }
// }while(!exit);
// }
    

// int main(){
//     menu();
//     return 0;
// }


#include <string>

// void menu(){
//     int choice;
//     int n;
//     char y;
//     cout << "How many strings? ";
//     cin >> n;
//     cin.ignore();
//     char exit;
//     string* arr = new string[n];
//     // bool exit = false; //new

//     do {
//         cout << "\nMenu:\n";
//         cout << "1. CREATE\n";
//         cout << "2. DISPLAY\n";
//         cout << "3. INSERT (not implemented)\n";
//         cout << "4. DELETE (not implemented)\n";
//         cout << "5. LINEAR SEARCH (not implemented)\n";
//         cout << "6. EXIT\n";
//         cout << "Enter choice: ";
//         cin >> choice;
//         cin.ignore(); // flush newline before getline()

//         switch(choice){
//             case 1:
//                 for (int i = 0; i < n; i++) {
//                     cout << "Enter string #" << i+1 << ": ";
//                     getline(cin, arr[i]);
//                 }
//                 break;

//             case 2:
//                 cout << "You entered:\n";
//                 for (int i = 0; i < n; i++) {
//                     cout << arr[i] << endl;
//                 }
//                 break;
//             case 6:
//                 return;
//                 break;
//             default:
//                 cout << "Invalid choice. Try again.\n";
//         }
//         cout << "Would you like to continue : y/n ";
        
//         cin >> y;

//     } while (y);

//     delete[] arr; // Clean up memory
// }

// int main(){
//     menu();
//     return 0;
// }



// 1) Developa Menudrivenprogramtodemonstrate the followingoperations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT

// void create(string*& arr, int &size){
//     cout << "Enter the number of elements";
//     cin >> size;
//     cin.ignore();
//     int i;
//     arr = new string[size];

//     for(i= 0;i< size;i++){
//         cout << "Enter String" << i + 1 << "=";
//         getline(cin,arr[i]); // we write cin here to tell the computer to take the input from the keyboard 
//     }

// }

// void display(string* arr,int size){
//     int i;
//     cout << "Menu = " << endl;
//     for(i=0;i<size;i++){
//         cout << arr[i] << endl;
//     }
// }

// void insert(string*& arr,int& size){
//     int pos,i;
//     string newStr;
//     cout << "Enter positon to insert " << size << " :";
//     cin >> pos;
//     cin.ignore();
//     cout << "Enter new string ";
//     getline(cin,newStr);
//     string* newArr = new string[size+1];
    
//     for(i=0;i<pos;i++){
//         newArr[i] = arr[i];
//     }

//     newArr[pos] = newStr;

//     for(i=pos;i<size;i++){
//         newArr[i+1] = arr[i];

//     }
//     delete[] arr;
//     arr = newArr;
//     size++;
//     cout << "String inserted" << endl;
// }

// void deleteAt(string*& arr, int& size){
//     int pos,i;
//     cout <<" Enter the position of the element you would like to delete" << size << " : ";
//     cin >> pos;


//     string* newArr = new string[size -1];
//     for(i=0;i<pos;i++){
//         newArr[i] = arr[i];
//     }
//     for(i=pos + 1;i<size;i++){
//         newArr[i-1] = arr[i];
//     }
//     delete[] arr;
//     arr =newArr;
//     size--;
// }

//   void linearSearch(string* arr, int size){
//     string target;
//     cout << "Enter String to be searched";
//     cin.ignore();
//     getline(cin,target);

//     bool found = false;
//     for(int i=0;i<size;i++){
//         if(arr[i] == target){
//             cout << "Found at position" << i << endl;
//             found = true;
//             break;
//         }
//         if(!found){
//             cout << "String not found" << endl;
//         }
//     }

//   }


// void menu(){
//     string* arr = nullptr;
//     int size = 0;
//     int choice;
//     bool exit = false;
//     while (!exit){
//         cout << "\n MENU \n";
//         cout << "1. CREATE\n";
//         cout << "2. DISPLAY\n";
//         cout << "3. INSERT\n";
//         cout << "4. DELETE\n";
//         cout << "5. LINEAR SEARCH\n";
//         cout << "6. EXIT\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//          switch (choice) {
//             case 1:
//                 if (arr != nullptr) delete[] arr;
//                 create(arr, size);
//                 break;
//             case 2:
//                 display(arr, size);
//                 break;
//             case 3:
//                 insert(arr, size);
//                 break;
//             case 4:
//                 deleteAt(arr, size);
//                 break;
//             case 5:
//                 linearSearch(arr, size);
//                 break;
//             case 6:
//                 exit = true;
//                 break;
//             default:
//                 cout << "Invalid choice" << endl;
//     }
// }
// delete[] arr;
// cout << "END";
// }

// int main(){
//     menu();
//     return 0 ;
// }

// !Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements.

// #include <iostream>
// using namespace std;

// void removeDuplicates(int arr[], int &n) {
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] == arr[j]) {
//                 for (int k = j; k < n - 1; k++) {
//                     arr[k] = arr[k + 1];
//                 }
//                 n--;  
//                 j--;    
//             }
//         }
//     }
// }

// int main() {
//     int arr[100], n;

//     cout << "Enter number of elements: ";
//     cin >> n;

//     cout << "Enter " << n << " elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     removeDuplicates(arr, n);

//     cout << "Array after removing duplicates: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


// ?Reverse the elements of an array

// int revNum(int arr[], int n) {

// 	for(int i=0;i<n/2;i++){
// 	int temp = arr[i];
// 	arr[i] = arr [n-1-i];
// 	arr [n-1-i] = temp;
//     }
// 	return 0;
// }

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
// 	cin >> arr[i];
//     }
//     revNum(arr ,n);
//     for (int i = 0; i <n; i++)
//     {
//         cout << arr[i]<<endl;
//     }

//     return 0;
// }


// b. Find the matrix multiplication


// // ! Write a program to find sum of every row and every column in a two-dimensional array. 

// #include <iostream>
// using namespace std;

// int main() {
//     int rows, cols;
//     cout << "Enter number of rows: ";
//     cin >> rows;
//     cout << "Enter number of columns: ";
//     cin >> cols;

//     int arr[100][100];

//     cout << "Enter elements of the array:\n";
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             cin >> arr[i][j];
//         }
//     }

//     cout << "\nSum of each row:\n";
//     for (int i = 0; i < rows; i++) {
//         int rowSum = 0;
//         for (int j = 0; j < cols; j++) {
//             rowSum += arr[i][j];
//         }
//         cout << "Row " << i + 1 << ": " << rowSum << endl;
//     }

//     cout << "\nSum of each column:\n";
//     for (int j = 0; j < cols; j++) {
//         int colSum = 0;
//         for (int i = 0; i < rows; i++) {
//             colSum += arr[i][j];
//         }
//         cout << "Column " << j + 1 << ": " << colSum << endl;
//     }

//     return 0;
// }

// ? b. Find the matrix multiplication