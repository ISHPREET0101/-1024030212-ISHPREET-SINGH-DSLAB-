#include<iostream>
using namespace std;
// ? Reverse the elements of an array

int revNum(int arr[], int n) {

	for(int i=0;i<n;i++){
	int temp = arr[i];
	arr[i] = arr [n-1-i];
	arr [n-1-i] = temp;
    }
	return 0;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
	cin >> arr[i];
    }
    revNum(arr ,n);
    for (int i = 0; i <n; i++)
    {
        cout << arr[i]<<endl;
    }

    return 0;
}


// ? b. Find the matrix multiplication
#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    
    // Input dimensions
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    // Check if multiplication is possible
    if (c1 != r2) {
        cout << "Matrix multiplication not possible " << endl;
        return 0;
    }

    int A[100][100], B[100][100], C[100][100] = {0};

    // Input matrix A
    cout << "Enter elements of first matrix (A):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    // Input matrix B
    cout << "Enter elements of second matrix (B):\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    // Matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) { 
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output result
    cout << "Resultant matrix (C = A × B):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


// TODO c. Find the Transpose of a Matrix

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[100][100], transpose[100][100];

    
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Calculate 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j]; // swap row and column
        }
    }

    // Display 
    cout << "\nTranspose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
