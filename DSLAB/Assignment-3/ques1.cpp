// ? 1. Develop a menu driven program demonstrating the following operations on a Stack using array: 
// ? (i) push(),  (ii) pop(),  (iii) isEmpty(),  (iv) isFull(),  (v) display(), and  (vi) peek(). 
#include<bits/stdc++.h>
using namespace std;

int arr[5];
int top = -1; 

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == 5 - 1);
}

void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Nothing to pop." << endl;
    } else {
        cout << arr[top--] << " popped from stack." << endl;
    }
}
 
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty. Nothing to peek." << endl;
    } else {
        cout << "Top element: " << arr[top] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "  Menu  " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop"<< endl;
        cout << "3. Peek" << endl;
        cout << "4. Empty" << endl;
        cout << "5. Full" << endl;
        cout << "6. Display" << endl; 
        cout << "7. Exit" << endl;
        cout << "Enter your choice = ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push = " << endl;
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3: 
                cout << "Top value = ";
                peek();
                break;

            case 4:
                if (isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is not empty" << endl;
                break;

            case 5:
                if (isFull())
                    cout << "Stack is full" << endl;
                else
                    cout << "Stack is not full" << endl;
                break;

            case 6:
                display();
                break;

            case 7:
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid input" << endl;
        }
    } while (choice != 7);

    return 0;
}
