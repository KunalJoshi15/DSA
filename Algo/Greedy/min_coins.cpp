#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<climits>

using namespace std;

int minCoins(int coin[],int n,int amount){
	sort(coin,coin+n);

	int res = 0;
	for(int i=n-1;i>=0;i--){
		if(coin[i]<=amount){
			int c = floor(amount/coin[i]);

			res = res+c;
			amount = amount-c*coin[i];
		}
		if(amount==0){
			break;
		}
	}
	return res;
}

int main()
{
	int coin[] = {5,10,2,1},n=4,amount=57;
	cout<<minCoins(coin,n,amount);
}

/*
The architecture for all the greedy algorithm is similar. We check whether the particular solution is feasible or not if it is feasible then we add it to the answer.
*/