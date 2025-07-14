// Word Ladder-I | Shortest paths
// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
// Keep the following conditions in mind:
// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord,
// startWord may or may not be part of the wordList.
// The second part of this problem can be found here

// beginword = "hit"  endword = "cog"
// wordlist = [hot,dot,dog,lot,log,cog]
// hit-> hot->dot->dog->cog = shortest path

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int wordLadderLength(string startWord,string targetWord,vector<string> &wordList){
        queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == targetWord) return steps;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a'; ch <='z'; ch++){
                    word[i] = ch;
                    //it exists in the set 
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
// tc - wordlength*26*N*logN
// sc-o(n)

int main(){
    return 0;
}
