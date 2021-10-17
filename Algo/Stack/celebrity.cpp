// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;
  
// Max # of persons in the party
#define N 8
  
// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
 /*
This particular way is the naive way of solving the celebrity problem.
in this case we will check each cell whether one person knows the other.
This can be seen as a graph problem in which all the degrees of the elements has the in degree and no out degree.
 */
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
  
// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    //the graph needs not be constructed
    //as the edges can be found by
    //using knows function
     
    //degree array;
    int indegree[n]={0},outdegree[n]={0};
     
    //query for all edges
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x = knows(i,j);
             
            //set the degrees
            outdegree[i]+=x;
            indegree[j]+=x;
        }
    }
    // here for a particular element to be a celebrity the indegree should be n-1 and the outdegree should be 0.
    // The vertex is simply a sink vertex.
    //find a person with indegree n-1
    //and out degree 0
    for(int i=0; i<n; i++)
    if(indegree[i] == n-1 && outdegree[i] == 0)
        return i;
     
    return -1;
}
// OTHER WAYS TO SOLVE THE CELEBRITY PROBLEM.
bool knows_matrix(vector<vector<int>> &arr,int a, int b) { return arr[a][b]; }

int findPotentialCelebrity(vector<vector<int>> &arr,int n){
	// this base case means that if there are no people then there is no celebrity.
	if(n==0) return -1;

	int id = findPotentialCelebrity(n-1);

	if(id==-1){
		return n-1;
	}
	else if(knows_matrix(arr,id,n-1)){
		return n-1;
	}
	else if(knows_matrix(arr,n-1,id)){
		return id;
	}

	return -1;
}

int Celebrity(vector<vector<int>> &arr,int n){
	int id = findPotentialCelebrity(arr,n);

	if(id==-1){
		return id;
	}
	else{
		int c1 = 0;
		int c2 = 0;

		for(int i=0;i<n;i++){
			if(i!=id){
				c1 += knows(id,i);
				c2 += knows(i,id);
			}
		}
		if(c1==0 and c2==n-1){
			return id;
		}
	}
	return -1;
}

int stack_celebrity(vector<vector<int>> &arr,int a,int b){
	stack<int> s;

	for(int i=0i<n;i++){
		s.push(i);
	}

	while(s.size()>1){
		int A = s.top();
		s.pop();
		int B = s.top();
		s.pop()

		if(knows_matrix(arr,A,B)){
			s.push(B);
		}
		else if(knows_matrix(arr,B,A)){
			s.push(A);
		}
	}

	if(s.empty()) return -1;

	int C = s.top();
	s.pop();

	for(int i=0;i<n;i++){
		if(i!=C and (knows_matrix(arr,C,i)==1 || knows_matrix(arr,i,C)==0)){
			return -1;
		}
	}
	return C;
}
// Solution using the stack based approach. We will simply find the candidate which can be celebrity and then check whether the candidate that we are considering is a celebrity or not.
// Driver code
int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" :
               cout << "Celebrity ID " << id;
    return 0;
}