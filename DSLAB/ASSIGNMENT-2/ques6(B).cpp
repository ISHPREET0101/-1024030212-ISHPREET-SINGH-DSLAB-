// ! incompelete
#include<iostream>
using namespace std;

int sparseMatrix(int arr[10][10],int rows,int cols,int sparse[50][3]){
    int k=1;
    int size =0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j] != 0){
                size++;
            }
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = size+1;

    // ? sparse matrix
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }
    return size + 1;
}

void display(int sparse[50][3],int size){
    cout << "Sparse matrix = " << endl;
    for (int i=0;i<size;i++){
        for(int j=0;j<3;j++){
            cout << sparse[i][j] << " " ;
        }
        cout << endl;
    }

}

void addSparse(int arrA[50][3], int arrB[50][3], int arrC[50][3]){
    if( arrA[0][0] != arrB[0][0] || arrA[0][1] != arrB[0][1]){
        cout << "Addition not possible" << endl;
    }

    int m = arrA[0][2];
    int n = arrB[0][2];
    int i=1, j=1, k=1;

    arrC[0][0] = arrA[0][0];
    arrC[0][1] = arrA[0][1];


}

int main() {
    // Sparse Matrix A (4x4, 4 non-zeros)
    int arrA[50][3] = {
        {4, 4, 4},
        {0, 0, 5},
        {1, 1, 8},
        {2, 2, 3},
        {3, 0, 6}
    };

    // Sparse Matrix B (4x4, 3 non-zeros)
    int arrB[50][3] = {
        {4, 4, 3},
        {0, 0, 4},
        {1, 2, 7},
        {3, 0, 9}
    };

    int arrC[50][3]; // Result

    cout << "Matrix A (Sparse):\n";
    

    cout << "Matrix B (Sparse):\n";
    

    

    cout << "Resultant Matrix (Sparse A+B):\n";
    

    return 0;
}