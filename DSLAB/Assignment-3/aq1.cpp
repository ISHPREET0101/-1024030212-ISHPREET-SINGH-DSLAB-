// 1. Given an array A, find the nearest smaller element for every element A[i] in the
//  array such that the element has an index smaller than i. 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int>smallest(vector<int>&A) {
    stack<int>str;
    vector<int>G;

    for(int i=0; i<A.size();i++) {
        while(!str.empty() && str.top()>= A[i]) {str.pop();}

        if(str.empty()) {
            G.push_back(-1);
        }else {
            G.push_back(str.top());
        }
str.push(A[i]);
    }
return G;
}

int main() {
    vector<int> A ={4,6,1,9,4,14};
    vector<int> G =smallest(A);

    cout << "Nearest smallest element =  ";
    for(int j=0;j<G.size();j++){
         cout << G[j] << " ";
    }
    cout << endl;

    return 0;
}
