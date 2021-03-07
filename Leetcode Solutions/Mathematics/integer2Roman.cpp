#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int number[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;
        string ans="";
        while(num>0){
            int div=num/number[i];
            num=num%number[i];
            
            while(div--){
                ans=ans+sym[i];
            }
            i--;
        }
        return ans;
        // All the numbers which have a little different representation are represented here so that for those the answer can be determined directly.
        
    }
};

int main(){
    int number=10;
    Solution s;
    string ans=s.intToRoman(number);
    return;
}