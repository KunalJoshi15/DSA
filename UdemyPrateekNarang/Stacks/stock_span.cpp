#include<bits/stdc++.h>

using namespace std;

vector<int> findSpan(vector<int> &input)
{
    // In this particular problem we will be using the stack in order to reduce the time complexity of the problem.
    vector<int> solution;
    stack<int> s;
    s.push(0);
    solution.push_back(1);
    for(int i=1;i<=input.size()-1;i++){
        int currentPrice = input[i];
        while(!s.empty() and input[s.top()]<=currentPrice){
            s.pop();
        }
        // The push and the pop of the elements is being only performed once hence the overall time complexity will be O(n)
        if(!s.empty()){
            int prev_highest = s.top();
            solution.push_back(i-prev_highest);
        }
        else{
            solution.push_back(i+1);
        }
        // push the element into the stack;
        s.push(i);
    }
    return solution;
}

int main()
{
    vector<int> input = {100,80,60,70,60,70,85};
    vector<int> solution = findSpan(input);

    for(int i:solution){
        cout<<i<<endl;
    }
}