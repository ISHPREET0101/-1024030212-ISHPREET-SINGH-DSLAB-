#include<iostream>
using namespace std;

int matrix(int arr[][3],int rows,int cols){  //without input

    bool isDiagonal = false;
    // ? diagonal matrix
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if((i == j) && arr[i][j] != 0 ){
                    isDiagonal = true;
            }
        }
    }

    if(isDiagonal) {
    cout << "This is a Diagonal Matrix" << endl;
    } 

    // ? lower triangular matrix
    bool isLowerTriangular = true;
    for(int i=0;i<rows;i++){
        for(int j=i+1;j<cols;j++){  
                if(arr[i][j] != 0){
            isLowerTriangular = false;
            }
        }
    }

    if(isLowerTriangular) {
        cout << "This is a Lower Triangular Matrix" << endl;
    } 

    // ? upper triangular matrix
    bool isUpperTriangular = true;
    for(int i=0;i<rows;i++){
        for(int j=0;j<i;j++){  
            if(arr[i][j] != 0){
            isUpperTriangular = false;
            }
        }
    }

    if(isUpperTriangular) {
    cout << "This is an Upper Triangular Matrix" << endl;
    } 

    // ? symmetryic matrix
    bool isSymmetric = true;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j] != arr[j][i]){
            isSymmetric = false;
            }
        }
    }

    if(isSymmetric){
         cout << "This is a Symmetric Matrix" << endl;
    } 

    // ? Tri-Diagonal Matrix
    bool isTriDiagonal = true;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(abs(i-j) > 1 && arr[i][j] != 0){
            isTriDiagonal = false;
            }
        }
    }

    if(isTriDiagonal){
        cout << "This is a Tri-Diagonal Matrix" << endl;
    }
    // ! sparse matric code
    cout << "Sparse matrix" << endl;
    int size=0,k=1;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j] != 0){
                size++;
            }
        }
    }

    int sparseMatrix[size+1][3];
    sparseMatrix[0][0] = rows;
    sparseMatrix[0][1] = cols;
    sparseMatrix[0][2] = size;
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j] != 0){
            sparseMatrix[k][0] = i;
            
            sparseMatrix[k][1] = j;
            
            sparseMatrix[k][2] = arr[i][j];
            
            k++;
            }
        }
    }

    for(int i=0;i<size+1;i++){
    for(int j=0;j<3;j++){
        cout << sparseMatrix[i][j] << " ";
    }
    cout << endl;
    }   

    return 0;
}


int main(){
    int arrA[3][3] ={
        {1,0,0},
        {0,2,0},
        {0,0,3}
    };

    int arrB[4][4] ={
        {1,2,0,0},
        {3,4,1,0},
        {0,2,3,4},
        {0,0,1,2}
    };

    int arrC[3][3] ={
        {1,0,0},
        {4,5,0},
        {7,8,9}
    };

    int arrD[3][3] ={
        {1,2,3},
        {0,4,5},
        {0,0,5}
    };

    int arrE[3][3] ={
        {1,1,-1},
        {1,2,0},
        {-1,0,-5}
    };

    matrix(arrA,3,3);
   
    return 0;
}