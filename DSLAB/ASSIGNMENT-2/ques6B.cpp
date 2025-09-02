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


int addSparse(int arrA[50][3], int arrB[50][3], int arrC[50][3]){
    int i=1,j=1,k=1;

    arrC[0][0] = arrA[0][0];
    arrC[0][1] = arrA[0][1];

    while(i <= arrA[0][2] && j <= arrB[0][2]) {
        if(arrA[i][0] < arrB[j][0] || (arrA[i][0] == arrB[j][0] && arrA[i][1] < arrB[j][1])) {           
            arrC[k][0] = arrA[i][0];
            arrC[k][1] = arrA[i][1];
            arrC[k][2] = arrA[i][2];
            i++; 
            k++;
        }else if(arrB[j][0] < arrA[i][0] || (arrB[j][0] == arrA[i][0] && arrB[j][1] < arrA[i][1])) {
            arrC[k][0] = arrB[j][0];
            arrC[k][1] = arrB[j][1];
            arrC[k][2] = arrB[j][2];
            j++; 
            k++;
        }else
{
            int sum = arrA[i][2] + arrB[j][2];
            if(sum != 0) {
                arrC[k][0] = arrA[i][0];
                arrC[k][1] = arrA[i][1];
                arrC[k][2] = sum;
                k++;
            }
            i++; 
            j++;
        }
    }

    while (i <= arrA[0][2]) {
        arrC[k][0] = arrA[i][0];
        arrC[k][1] = arrA[i][1];
        arrC[k][2] = arrA[i][2];
        i++; k++;
    }

    while (j <= arrB[0][2]) {
        arrC[k][0] = arrB[j][0];
        arrC[k][1] = arrB[j][1];
        arrC[k][2] = arrB[j][2];
        j++; k++;
    }

    arrC[0][2] = k - 1;  
    return k;
}

int main() {
 
    int arrA[50][3] = {
        {4, 4, 4},
        {0, 0, 5},
        {1, 1, 8},
        {2, 2, 3},
        {3, 0, 6}
    };

    int arrB[50][3] = {
        {4, 4, 3},
        {0, 0, 4},
        {1, 2, 7},
        {3, 0, 9}
    };
    
    int arrC[50][3]; 

    cout << "Matrix A = " << endl;
    display(arrA, arrA[0][2] + 1);
    cout << endl;
    cout << "Matrix B  = " << endl;
    display(arrB,arrB[0][2] +1);
    cout << endl;
    int sizeC = addSparse(arrA,arrB,arrC);
    cout << endl;
    cout << "arrA + aarB = ";
    display(arrC,sizeC);
    return 0;
}