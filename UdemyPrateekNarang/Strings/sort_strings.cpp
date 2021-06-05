#include<bits/stdc++.h>

using namespace std;

string extractStringAtKey(string str,int key){
    //string tokeniser
    //hello how are you;

    // str.c_str() function is used to conver the string into the charater array as the string tokeniser function requires a character array as the first paramter.
    char *s = strtok((char*)str.c_str()," "); 
    // This particular function will give us the particular column from the string that is provided to us.
    while(key>1){
        s = strtok(NULL," ");
        key--;
    }
    return (string)s;
}

int convertToInt(string s){
    int ans=0;
    int p=1;

    for(int i=s.length()-1;i>=0;i--){
        ans+=((s[i]-'0')*p);
        p=p*10;
    }
    return ans;
}

bool lexicoComparator(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2 = s2.second;

    return key1<key2;
}

bool numericComparator(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2 = s2.second;

    return convertToInt(key1)<convertToInt(key2);
}

int main()
{
    /*
    The problem statement is as follows.
    We are provided with the strings which are seperated by the spaces.
    We need to perform few operations as per our own requirements.
    3
    92 022
    82 12
    77 13
    2 false numeric
    numeric means that the numeric value will be checked and lexicographically means that the lexicographic value is checked.
    false means reversing is not done in this particular case.
    
    Solution technique is done this way.
    1) Extract the keys from every strings.-> Tokenisation is to be performed.
    2) Sort the arrays two comparators need to done.
    3) Reverse is true then call the reverse function. String and the keys are checked as per our own requirement.
    */
    int n;
    cin>>n;
    cin.get(); // Consumes the eextra \n;
    string temp;
    vector<string> v;
    for(int i=0;i<n;i++){
        getline(cin,temp);
        v.push_back(temp);
    }

    int key;
    string reversal,ordering;
    cin>>key>>reversal>>ordering;
    // cin excludes the whitespaces which are being mentioned.
    // 1.extract tokens.
    vector<pair<string,string>> vp;

    for(int i=0;i<n;i++){
        vp.push_back({v[i],extractStringAtKey(v[i],key)});
    }

    if(ordering=="numeric"){
        sort(vp.begin(),vp.end(),numericComparator);
    }
    else{
        sort(vp.begin(),vp.end(),lexicoComparator);
    }

    if(reversal=="true"){
        reverse(vp.begin(),vp.end());
    }

    for(int i=0;i<n;i++){
        cout<<vp[i].first<<endl;
    }
}