#include <bits/stdc++.h>
using namespace std;
int smallercount(vector<int> arr,int n){
    // set always sorts the element which comes.
    set<int> s;
    int maxcount = 0;
    for(int i=n-1;i>=0;i--){
        s.insert(arr[i]);
        int dist = distance(s.begin(),s.find(arr[i]));
        maxcount = max(maxcount,dist);
    }
    return maxcount;
}
int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int size;
	    cin>>size;
	    vector<int> arr;
	    for(int i=0;i<size;i++){
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    int ans = smallercount(arr,size);
	    cout<<ans<<endl;
	}
	return 0;
}