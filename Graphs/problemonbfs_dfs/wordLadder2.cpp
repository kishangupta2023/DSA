// Word Ladder - 2 
// the previous is enough u can learn this as the previous one may give TLE

// -> step 1 . just do the previous solution with storing in a map in the queue 
// -> step 2 . backtrack in the map from end -> begin to get the asnwer 

#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<string,int> mpp;
    vector<vector<string>>ans;
    string b;
    private:
    void dfs(string word,vector<string> &seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mpp[word];
        for(int i=0;i<b.size();i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(mpp.find(word) != mpp.end() && mpp[word] +1 == steps){
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                  
                }
                word[i] = original;
        }
    }
    public:
    vector<vector<string>> findLadders(string beginWord,string endWord,vector<string>&wordList){
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string>q;
        b = beginWord;
        q.push({beginWord});
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word == endWord) break;
            for(int i=0;i<sz;i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps+1;
                    }
                }
                word[i] = original;
            }
        }
        for(auto it: mpp) cout<<it.first << " " << it.second <<endl;
        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }

};
int main(){

}