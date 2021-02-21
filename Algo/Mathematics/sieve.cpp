#include<bits/stdc++.h>

using namespace std;
void sieve(){
    vector<bool> isPrime(n+1,true);

    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i]){
            for(int j=2*i;j<=n;j=j+i)
            {
                isPrime[i]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
}
int main()
{

}