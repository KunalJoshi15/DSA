#include<bits/stdc++.h>

using namespace std;

string simplifiedPath(string s){
	istringstream iss(s);
	vector<string> tokens;
	string token;

	while(getline(iss,token,'/')){
		if(token=="." or token==""){
			continue;
		}
		tokens.push_back(token);
	}
	bool relative = false;
	if(s[0]!='/'){
		relative=true;
	}
	vector<string> p;

	for(string token:tokens){
		if(token==".."){
			if(relative and p[p.size()-1]==".."){
				p.push_back(token);
			}else{
				p.pop_back();
			}
		}
		else{
			p.push_back(token);
		}
	}
	if(p.size()==0 and !relative) return "/";
	ostringstream oss;
	int i=0;
	
	return oss.str();
}

string simplifyPath1(string path) {
        // This is solvable using stacks as well.
		// Here in this particular code we are considering the current elements.
        stack <string> st;
        for(int i = 0;i<path.size();i++)
        {
            if(path[i] == '/')
                continue;
            string s;
            while(i<path.size() && path[i] != '/')
            {
                s += path[i];
                i++;
            }
            if(s == ".")
                continue;
            else if(s == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(s);
        }
        string res;
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        if(res.size() == 0)
            return "/";
        return res;
    }

int main()
{
	string s;
	cin>>s;
	string output = simplifiedPath(s);
	cout<<output;
}