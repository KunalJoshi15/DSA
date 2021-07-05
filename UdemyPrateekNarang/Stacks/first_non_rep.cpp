#include<bits/stdc++.h>

using namespace std;
// Here we can simply use the hashmap itself it will provide us a time complexity of O(n^2) in order to reduce this particular time complexity we can be using the queue data structure as per our own requirement.
// We remove the elements from the queue when their frequencies become greater than 1.


int main()
{
    //Here we do a left to right scanning each time and then simply check the frequency of the characters occured if a particular character has the frequency more than that is deemed then. It is an issue.
    queue<char> q;
    int freq[27] = {0};

    char ch;
    cin>>ch;

    while(ch!='.'){
        //Letter
        q.push(ch);
        freq[ch-'a']++;

        // QUERTY IF THE QUEUE IS NOT EMPTY WE CHECK THE FREQUENCY OF THE CHARACTER WHICH IS AT THE FRONT OF THE QUEUE.
        while(!q.empty()){
            int idx = q.front()-'a';
            if(freq[idx]>1){
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty()){
            cout<<"-1"<<endl;
        }
        cin>>ch;
        // each time the character input is taken and the stream of the characters can be stopped by simply pressing a .
    }
}