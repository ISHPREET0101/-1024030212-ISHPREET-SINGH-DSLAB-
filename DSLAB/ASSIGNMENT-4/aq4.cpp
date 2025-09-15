// 4) The school cafeteria offers circular and square sandwiches at lunch break, referred to by
// numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or
// circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The
// sandwiches are placed in a stack. At each step:
// • If the student at the front of the queue prefers the sandwich on the top of the stack, they will take
// it and leave the queue.
// • Otherwise, they will leave it and go to the queue's end.
// This continues until none of the queue students want to take the top sandwich and are thus
// unable to eat
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for(int a:students){
            q.push(a);
        }

        int i = 0;
        int count = 0; // for avoiding infinite loop case when nobody wants the sandwich

        while(!q.empty() && count < q.size()){
            if(q.front() == sandwiches[i]){
                q.pop();
                i++;
                count = 0;
            }else{
                q.push(q.front());
                q.pop();
                count++;
            }  
        }
        return q.size();
    }
};