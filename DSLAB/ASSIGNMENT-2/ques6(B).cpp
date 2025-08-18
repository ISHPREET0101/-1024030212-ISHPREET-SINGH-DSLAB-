// 6) Write a program to implement the following operations on a Sparse Matrix, 
// assuming the matrix is represented using a triplet. 
// (b) Addition of two matrices. 
//
#include <iostream>
using namespace std;

void printSparse(int sparse[100][3]) {
    int nonZero = sparse[0][2];
    cout << "Row Col Val " << endl;
    for (int i = 0; i <= nonZero; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
    cout << endl;
}

void addSparse(int A[100][3], int B[100][3], int C[100][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrix dimensions do not match. Cannot add!" << endl;
        return;
    }

    int i = 1, j = 1, k = 1;
    int totalA = A[0][2], totalB = B[0][2];
    while (i <= totalA && j <= totalB) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; 
            k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; 
            k++;
        }
        else {
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; 
            j++;
        }
    }

    while (i <= totalA) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; 
        k++;
    }
    while (j <= totalB) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; 
        k++;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];
    C[0][2] = k - 1;
}

int main() {
    int A[100][3], B[100][3], C[100][3];
    A[0][0] = 3; A[0][1] = 3; A[0][2] = 3; 
    A[1][0] = 0; A[1][1] = 0; A[1][2] = 1;
    A[2][0] = 1; A[2][1] = 1; A[2][2] = 2;
    A[3][0] = 2; A[3][1] = 2; A[3][2] = 3;

    B[0][0] = 3; B[0][1] = 3; B[0][2] = 3;
    B[1][0] = 0; B[1][1] = 0; B[1][2] = 4;
    B[2][0] = 1; B[2][1] = 2; B[2][2] = 5;
    B[3][0] = 2; B[3][1] = 2; B[3][2] = 6;
    cout << "Sparse Matrix A:\n";
    printSparse(A);
    cout << "Sparse Matrix B:\n";
    printSparse(B);
    addSparse(A, B, C);
    cout << "Resultant Sparse Matrix (A + B):\n";
    printSparse(C);
    return 0;
}
