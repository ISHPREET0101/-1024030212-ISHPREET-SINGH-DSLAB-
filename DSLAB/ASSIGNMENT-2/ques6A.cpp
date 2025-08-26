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

void transpose(int sparse[50][3],int size){
    for(int i=0;i<size;i++){
        int temp = sparse[i][0];
        sparse[i][0] = sparse[i][1];
        sparse[i][1] = temp;
    }

    for(int i=1;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(sparse[i][0] > sparse[j][0] || (sparse[i][0] == sparse[j][0] && sparse[i][1] > sparse[j][1])){
                for(int k=0;k<3;k++){
                    int temp = sparse[i][k];
                    sparse[i][k] = sparse[j][k];
                    sparse[j][k] = temp;
                }
            }
        }
    }
}

int main(){
    int arr[10][10] = {
        {0, 0, 3, 0},
        {22, 0, 0, 0},
        {0, 12, 0, 0},
        {0, 8, 0, 39}
    };

    int rows = 4, cols = 4;
    int sparse[50][3], trans[50][3];

    int size = sparseMatrix(arr, rows, cols, sparse);
    display(sparse,size);
    transpose(sparse,size);
    display(sparse,size);
    return 0;
}