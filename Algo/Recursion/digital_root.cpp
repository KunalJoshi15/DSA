#include<bits/stdc++.h>

using namespace std;

int digitalRoot(int n){
    if(n<=9) return n;
    // This particular program finds the digitalRoot and then find the modulus as per our need therefore the other actions are performed according to it.
    // Here we will be finding the smaller answer and then according to it the next steps are taken.
    int smallAns = n%10+digitalRoot(n/10);
    // Here we will be testing whether the small answer is smaller than the 9 value if it is so then we will simply return the value and if it is not so then we will call the digitalRoot(smallAns)
    if(smallAns<=9) return smallAns;
    else{
        return digitalRoot(smallAns);
    }
}

int main(){

}