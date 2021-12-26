class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset;
        bool isPresent = false;
        
        for(auto word: wordList){
            if(endWord.compare(word)==0) isPresent=true;// then there is no difference
            myset.insert(word);
        }
        // if the end word is not present in the dictionary itself then we return 0.
        if(isPresent==false) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(q.empty()==false){
            depth+=1;
            int lsize = q.size();
            while(lsize--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.length();i++){
                    string temp = curr;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(curr.compare(temp)==0){
                            continue;
                        }
                        if(temp.compare(endWord)==0){
                            return depth+1;
                        }
                        if(myset.find(temp)!=myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};