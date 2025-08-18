#include<iostream>
#include<string>
using namespace std;
void create(string*& arr, int &size){
    cout << "Enter the number of elements";
    cin >> size;
    cin.ignore();
    int i;
    arr = new string[size];

    for(i= 0;i< size;i++){
        cout << "Enter String" << i + 1 << "=";
        getline(cin,arr[i]); // we write cin here to tell the computer to take the input from the keyboard 
    }

}

void display(string* arr,int size){
    int i;
    cout << "Menu = " << endl;
    for(i=0;i<size;i++){
        cout << arr[i] << endl;
    }
}

void insert(string*& arr,int& size){
    int pos,i;
    string newStr;
    cout << "Enter positon to insert " << size << " :";
    cin >> pos;
    cin.ignore();
    cout << "Enter new string ";
    getline(cin,newStr);
    string* newArr = new string[size+1];
    
    for(i=0;i<pos;i++){
        newArr[i] = arr[i];
    }

    newArr[pos] = newStr;

    for(i=pos;i<size;i++){
        newArr[i+1] = arr[i];

    }
    delete[] arr;
    arr = newArr;
    size++;
    cout << "String inserted" << endl;
}

void deleteAt(string*& arr, int& size){
    int pos,i;
    cout <<" Enter the position of the element you would like to delete  " << size << " : ";
    cin >> pos;


    string* newArr = new string[size -1];
    for(i=0;i<pos;i++){
        newArr[i] = arr[i];
    }
    for(i=pos + 1;i<size;i++){
        newArr[i-1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

  void linearSearch(string* arr, int size){
    string target;
    cout << "Enter String to be searched";
    cin.ignore();
    getline(cin,target);

    bool found = false;
    for(int i=0;i<size;i++){
        if(arr[i] == target){
            cout << "Found at position" << i << endl;
            found = true;
            break;
        }
        if(!found){
            cout << "String not found" << endl;
        }
    }

  }


void menu(){
    string* arr = nullptr;
    int size = 0;
    int choice;
    bool exit = false;
    while (!exit){
        cout << "\n MENU \n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

         switch (choice) {
            case 1:
                if (arr != nullptr) delete[] arr;
                create(arr, size);
                break;
            case 2:
                display(arr, size);
                break;
            case 3:
                insert(arr, size);
                break;
            case 4:
                deleteAt(arr, size);
                break;
            case 5:
                linearSearch(arr, size);
                break;
            case 6:
                exit = true;
                break;
            default:
                cout << "Invalid choice" << endl;
    }
}
delete[] arr;
cout << "END";
}

int main(){
    menu();
    return 0 ;
}