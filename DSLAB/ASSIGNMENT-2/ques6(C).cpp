// 6) Write a program to implement the following operations on a Sparse Matrix, 
// assuming the matrix is represented using a triplet. 
// (c) Multiplication of two matrices. 
//
#include <iostream>
using namespace std;

void printSparse(int sparse[100][3]) {
    int nonZero = sparse[0][2];
    cout << "Row Col Val";
    for (int i = 0; i <= nonZero; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
    cout << endl;
}

void multiplySparse(int A[100][3], int B[100][3], int C[100][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Matrix multiplication not possible (A.cols != B.rows)" << endl;
        return;
    }

    int rowC = A[0][0], colC = B[0][1];
    int temp[100][3];
    int k = 1;

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {
            if (A[i][1] == B[j][0]) { 
                int row = A[i][0];
                int col = B[j][1];
                int val = A[i][2]*B[j][2];

                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (temp[x][0] == row && temp[x][1] == col) {
                        temp[x][2]+= val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    temp[k][0] = row;
                    temp[k][1] = col;
                    temp[k][2] = val;
                    k++;
                }
            }
        }
    }

    temp[0][0] = rowC;
    temp[0][1] = colC;
    temp[0][2] = k - 1;

    for (int i = 0; i <= temp[0][2]; i++) {
        C[i][0] = temp[i][0];
        C[i][1] = temp[i][1];
        C[i][2] = temp[i][2];
    }
}

int main() {
    int A[100][3], B[100][3], C[100][3];

    A[0][0] = 3; A[0][1] = 3; A[0][2] = 2;
    A[1][0] = 0; A[1][1] = 0; A[1][2] = 1;
    A[2][0] = 1; A[2][1] = 2; A[2][2] = 2;

    // Example Sparse Matrix B (3x3)
    B[0][0] = 3; B[0][1] = 3; B[0][2] = 2;
    B[1][0] = 0; B[1][1] = 1; B[1][2] = 3;
    B[2][0] = 2; B[2][1] = 2; B[2][2] = 4;

    cout << "Sparse Matrix A:\n";
    printSparse(A);
    cout << "Sparse Matrix B:\n";
    printSparse(B);
    multiplySparse(A, B, C);
    cout << "Resultant Sparse Matrix (A * B):\n";
    printSparse(C);
    return 0;
}
