#include<iostream>
#include<string>

using namespace std;

int main()
{
    // In this particular problem we will be replacing each space with %20. Therefore the movement will be equivalent to the number of space
    // We will be finding a particular absolute value where the characters will be moved.
    string s = "hello world,  how are you?";
    int spaces = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            spaces++;
        }
    }
    
    string solution(s.size()+spaces*2,' ');
    int m = s.size()+spaces*2-1;
    solution[m+1] = '/0';
    cout<<m;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==' '){
            solution[m] = '0';
            solution[m-1] = '2';
            solution[m-2] = '%';
            m=m-3;
        }else{
            solution[m]=s[i];
            m--;
        }
    }
    cout<<solution;
}