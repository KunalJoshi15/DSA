#include<bits/stdc++.h>

using namespace std;

bool isLuckyRec(int n,int counter){
    int number = n;

    if(counter>n) return true;
    if(n%counter==0) return false;
    number = number-number/counter;
    counter++;
    return isLuckyRec(number,counter);
    // The code base of the lucky number works as follows. the top condition is true when there is only one element 1.
    //then we can simply return true as it is a lucky number.
    /*
        counter variable is used to delete the particular elements which are present in a particular location.
        if the counter is greater than the value of n then we can simply say that the number is a lucky number.
        The counter will simply be greater than the number of elements which are left.
        np keeps the track of the next position number after the removal of the numbers.
        counter each time increases by the value of 1. We will be calling the isLucky number recursively.
    */
}

bool isLucky(int n){
    return isLuckyRec(n,2);
}