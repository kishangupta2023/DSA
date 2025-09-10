#include<bits/stdc++.h>
using namespace std;

string postToInfix(string s){
    stack<string>st;
    int i=s.size()-1;
    while(i >=0){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1,s[i])); // convert char to string 
        }
        else{
            if(st.size() < 2){
                return "Invalid expression";
            }
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            string ans = "("+first+s[i]+second+")";
            st.push(ans);
        }
        i--;
    }
    return st.size() == 1 ? st.top() : "Invalid expression";
}
// tc-0(N) +0(N)
//sc-0(N)
