#include<bits/stdc++.h>

using namespace std;

class TwoStacks{
	public:
		int *arr,cap,top1,top2;

		TwoStacks(int n){
			cap=n;
			top1=-1;
			top2=cap;
			arr = new int[n];
		}

		void push1(int x){
			if(top1<top2-1){
				top1++;
				arr[top1]=x;
			}
		}

		void push2(int x){
			if(top1<top2-1){
				top2--;
				arr[top2]=x;
			}
		}
		int pop1(){
			if(top1>=0){
				int x = arr[top1];
				top1--;
				return x;
			}
			else{
				exit(1);
			}
		}

		int pop2(){
			if(top2<cap){
				int x = arr[top2];
				top2++;
				return x;
			}
			else{
				exit(1);
			}
		}
};

int main()
{
	// In case of the two stacks implementation we will be having one error and form the left end we will be having one stack while from the other end we will be having other array with us.
	// There are two top variables maintained in this particular case. one is from the left side while the other one is from the right side.
	// This class will basically create two stacks in a particular array as per our requirement.
	// In case of the two stacks the overflow will happen when the top1 is 1 larger than the value of top2.
}
