#include<bits/stdc++.h>

using namespace std;

void sieve(int n)
{
    vector<bool> isPrime(n+1,true);
    // This particular algorithm is used to find the prime numbers we have to exclude some of the values which are the factors of 2 and 3
    // Here we will be taking the values and will then check whether they are prime or not 
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i]){
            for(int j=i*i;j<=n;j=j+i)
            {
                isPrime[i]=false;
            }
        }
    }
    // All the values which are composite will get the boolean value as false. while all the others will get the values as true. root of n complexity is considered 
    // As the divisors are always in pairs. In case of the normal sieve the loop of j starts from 2*i while in the other case the loop of j starts from i*i
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
            cout<<i<<" ";
    }
}
// The time complexity of the sieve algorithm is O(n log log n)

int main()
{
    
    return 0;
}