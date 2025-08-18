// 5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑐𝑜𝑙𝑢𝑚𝑛𝑠.
//  Assuming array is used to store elements of the following matrices, 
//  implement an efficient way that reduces the space requirement.
// (a) Diagonal Matrix. 
// (b) Tri-diagonal Matrix.
// (c) Lower triangular Matrix.
// (d) Upper triangular Matrix.
// (e) Symmetric Matrix 

#include<iostream>
using namespace std;

int inputMatrix(int rows,int cols){ //with input
    int arr[50][50];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << "Enter array elements [" << i << "][" << j << "] = ";
            cin >> arr[i][j];
            cout << endl;
        }
    }

    cout << "Input Matrix = " << endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << "[" << i << "][" << j << "] = " << arr[i][j] ;
        }
        cout << endl;
    }

    bool isDiagonal = true;
    // ? diagonal matrix
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if((i != j) && arr[i][j] != 0 ){
                    isDiagonal = false;
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
    

    int rows,cols;
    cout << "Enter the number of rows = ";
    cin >> rows ;
    cout << endl;
    cout << "Enter the number of columns = ";
    cin >> cols ;
    cout << endl;
    
    inputMatrix(rows,cols);
    return 0;
}