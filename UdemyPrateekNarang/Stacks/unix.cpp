#include<bits/stdc++.h>

using namespace std;

void simplifyPath(string path){
    //Here we will use the string tokenizer in order to split the array using the /.
    // We need to consider that if the string starts with / then it is simply an absolute path and that particular case needs to be treated differently.
    istringstreams iss(path);
    vector<string> tokens;
    string token;

    // This particular while loop is used for splitting the input string through delimeter / . and '' strings can be ignore as they will not be changing the relative path of the entire equation.

    while(getline(iss,token,'/')){
        if(token=="" or token=="."){
            continue;
        }
        else{
            tokens.push_back(token);
        }
    }

    // we will be pushing all the characters to the stack and then will remove the elements from the stack when the double dots are encountered.
    vector<string> s;
    if(path[0]=='/'){
        // This is used to identify whether the string in particular has the relative path or the absolute path.
        // Here the string in particular has the relative path and the absolute path.
        stack.push_back("");
    }
    for(string t:tokens){
        // If the token is .. then we will be removing the elements from the stack. We need to check whether we have specified the absolute path or the relative path.
        if(token==".."){
            // 2 cases abs path or relative path.
            if(stack.size()==0 or stack[stack.size()-1]==".."){
                // Here the case is for the reltaive path. If the stack size is 0 then simply there  is not element in the stack  currently. If this is the case then we will be pushing the .. into the stack.
                stack.push_back("..");
            }else if(stack[stack.size-1]==""]){
                // This is the case when the stack has the absolute path. 
                stack.pop_back();
            }
        }
        else{
            stack.push_back(token);
        }
    }

    if(stack.size()==1 and stack[0]==""){
        return "/"
    }
    ostringstream oss;
    for(auto token:stack){
        oss<<token<<"/";
    }
    return oss.str();
}

int main()
{
    string path = "/../x/y/../z/././w/a///../../c/./";
    simplifyPath(path);
}