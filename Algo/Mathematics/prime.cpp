#include<bits/stdc++.h>

using namespace std;

bool isPrime(int p)
{
    if(p==1) return false;
    for(int i=2;i*i<=p;i++)
    {
        if(p%i==0)
            return false;
    }
    return true;
}

bool efficientPrime(int o)
{
    if(o==1) return false;
    if(o==2||o==3) return true;
    if(o%2==0||o%3==0)
    for(int i=5;i*i<=o;i=i+6)
    {
        if(o%i==0||o%(i+2)==0)
            return false;
    }
    return true;
}

int main()
{
    int p;
    cin>>p;
    if(isPrime(p))
    {
        cout<<"Number is prime"<<endl;
    }
    else{
        cout<<"Number is not prime"<<endl;
    }
}