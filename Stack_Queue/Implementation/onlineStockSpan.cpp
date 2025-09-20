// Online stock Span problem
// max consecutive days for which the stock price was less than or equal to current day 

#include<bits/stdc++.h>
using namespace std;

class StockSpanner{

    vector<int>ans;
    vector<int>StackSpan(){
        ans = {};
    }
    int next(int val){
        ans.push_back(val);
        int cnt = 1;
        for(int i=ans.size()-2;i>=0;i--){
            if(ans[i] <= val) cnt++;
            else break;
        }
        return cnt;
    }
    //tc-0(No of days)
    //sc -0(total number of next calls)
};
class StockSpan{
private:
   stack<pair<int,int>>st;
   int ind;

public:
   StockSpan(){
    ind = -1;
   }

    int next(int val){
        ind++;
        while(!st.empty() && st.top().first <= val){
            st.pop();
        }
        int ans = ind -(st.empty() ? -1 : st.top().second);
        st.push({val,ind});
        return ans; 
    }
};
   //tc -0(2N)
   //sc-0(N)
