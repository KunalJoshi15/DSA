#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

void convert_matrix(vector<vector<int>> &arr){
	int rows = arr.size();
	int cols = arr[0].size();

	vector<int> row_matrix(rows,1);
	vector<int> col_matrix(cols,1);

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(arr[i][j]==0){
				row_matrix[i] = 0;
				col_matrix[j] = 0;
			}
		}
	}

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(row_matrix[i]==0 || col_matrix[j]==0){
				arr[i][j] = 0;
			}
		}
	}

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	vector<vector<int>> arr = {
		{1,2,0},
		{2,0,1},
		{3,4,2}
	};

	convert_matrix(arr);

	return 0;
}