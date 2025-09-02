#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// ? My approch time complexity O(n2)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        int count = 0;
        vector<int> answer(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(temperatures[i] < temperatures[j]){
                    count++;
                    answer[i] = count;
                    break;
                }else{
                    count++;
                }                
            }
            count = 0;
        }
        return answer;
    }    
};

// ? leetcode aproch , Time complexity = O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;  

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                answer[idx] = i - idx;  
            }
            st.push(i);
        }

        return answer;
    }
};
