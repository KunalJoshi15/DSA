#include<bits/stdc++.h>

using namespace std;

int main(){
    const int i=10;
    int j=12;
    const int &k=j;
    j++;
    cout<<k<<endl;
}
// Here we are making the path through k as constant Therefore any changes made from that path will not be reflected.
// Path becomes constant not a particular storage.

/*
There are certain things which are allowed while there are others which are not allowed.
int const j2=12;
int const &k2=j2;
Here both of them cannot be incremented.

int const j3=123
int &k=j3;

THis kind of the referencing is not allowed at all.
*/