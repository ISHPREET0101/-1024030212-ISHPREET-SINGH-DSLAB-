// 2) Develop a menu driven program demonstrating the following operations on Circular Queues:
// enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
#include<iostream>
using namespace std;

#define MAXLEN 8

class circularQueue{
    int arr[MAXLEN];
    int f, r;
    public:

    circularQueue(){
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
            cout << "Queue overflow "<< endl;
        }else{
            if(isEmpty()){
                f = 0;
            }
            r = (r+1)%MAXLEN;
            arr[r] = val;
            cout << "Item inserted " << val << " at index = " << r << endl;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty " << endl;
        }else{
            int val = arr[f];
            cout << "Item dequeued " << val << " from index " << f << endl;
            if(f == r){
                f = -1;
                r = -1;
            }else{
                f = (f+1)%MAXLEN;
            }
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
            cout << "Queue is empty" << endl;
        }else{
            int i = f;
            while(true){
                cout << arr[i] << " ";
                if(i==r){
                    break;
                }
                i = (i+1)%MAXLEN;
            }
        }
        cout << endl;
    }

};

int main(){
    circularQueue q;
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