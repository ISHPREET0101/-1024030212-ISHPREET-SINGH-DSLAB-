// 1) Develop a menu driven program demonstrating the following operations on simple
// Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
#include<iostream>
using namespace std;

#define MAXLEN 8

class queue{
    int arr[MAXLEN];
    int f, r;
    public:

    queue(){
        f = -1;
        r = -1;
    }
    
    bool isFull(){
        return (r+1)%MAXLEN == f;
    }

    bool isEmpty(){
        if(f == -1 || f>r){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int val){
        if(isFull()){
            cout << "Queue overflow " << endl;
        }else if(f == -1 && r == -1){
            f = 0;
            r = 0;
            arr[r] = val;
            cout << "Item inserted " << val << " at index = " << r;
        }else{
            r++;
            arr[r] = val;
            cout << "Item inserted " << val << " at index = " << r;
        }
    }

    void dequeue(){
        int val;
        if(isEmpty()){
            cout << "Queue is empty" << endl;
        }else if(f == 0 && r == 0){
            val = arr[f];
            cout << "Item found " << val << " at index " << f;
            f = -1;
            r = -1;
        }else{
            val = arr[f];
            cout << "Item found " << val << " at index " << f;
            f++;
        }
    }

    void peek(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
        }else{
            cout << "Front element = " << arr[f] << endl;
        }
    }

    void display(){
        if(isEmpty()){
            cout << "Qeue is empty" << endl;
        }else{
            for(int i=f;i<r;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

};

int main(){
    queue q;
    int choice, val;
    do{
        cout << " MENU " << endl;
        cout << " 1. Enqueue " << endl;
        cout << " 2. Dequeue " << endl;
        cout << " 3. Peek " << endl;
        cout << " 4. Display " << endl;
        cout << " 5. isEmpty " << endl;
        cout << " 6. isFull " << endl;
        cout << " 7. Exit " << endl;

        cout << "Enter your choice " << endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter a value to enqueue = " << endl;
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                if(q.isEmpty()){
                    cout << "Queue is empty " << endl;
                }else{
                    cout << "Queue is not empty " << endl;
                }
                break;
            case 6:
                if(q.isFull()){
                    cout << "Queue is full " << endl;
                }else{
                    cout << "Queue is not full " << endl;
                }
                break;
            case 7:
                cout << "End of program " << endl;
                break;
            default:
                cout << "Invalid choice " << endl;
                break;
        }
    }while(choice !=7);
    return 0;
}