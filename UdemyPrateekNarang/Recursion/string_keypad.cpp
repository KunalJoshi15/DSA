#include<iostream>
#include<cstring>

using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadOutput(string input,string output,int i=0){
	if(input[i]=='\0'){
		// In case we are using the character array then we will have to specify the character which is being used.
		cout<<output<<endl;
		return;
	}
	//Recursive Case
	int current_digit = input[i]-'0';
	if(current_digit==0 or current_digit==1){
		// Here we will be simply skipping the particular two digits.
		printKeypadOutput(input,output,i+1);
	}

	//keypad 
	for(int k=0;k<keypad[current_digit].size();k++){
		printKeypadOutput(input,output+keypad[current_digit][k],i+1);
	}
	return;
}

int main()
{
	string input;
	cin>>input;

	string output;
	printKeypadOutput(input,output);
}