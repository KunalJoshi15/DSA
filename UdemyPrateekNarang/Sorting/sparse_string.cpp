#include<bits/stdc++.h>

using namespace std;

int sparse_search(string a[],int n,string key){
	int s=0;
	int e=n-1;

	while(s<=e){
		int mid = (s+e)/2;
		int mid_left = mid-1;
		int mid_right = mid+1;
		if(a[mid]==""){
			// Update our mid to a value which is non empty.
			while(1){
				if(mid_left<s and mid_right>e){
					return -1;
				}else if(a[mid_right]!=""){
					mid = mid_right;
					break;
				}
				else if(a[mid_left]!=""){
					mid = mid_left;
					break;
				}
				mid_left--;
				mid_right++;
			}
		}
		else if(a[mid]==key) return mid;
		else if(a[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
}

int main()
{
	// In this particular algorithm we will be using the concept of binary search. First find the middle index,
	// If the string in the middle index is blank then we will be finding the nearest string that is reachable.

	string s[] = {"ai","","","","","bat","","","","algo"};

}