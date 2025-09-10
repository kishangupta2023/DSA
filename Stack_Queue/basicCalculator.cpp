// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
// Example 1:
// Input: s = "1 + 1"
// Output: 2
// Example 2:
// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        long long int sum =0;
        stack<pair<int,int>>st;
        int sign = 1;
        for(int i=0;i<s.size();i++){
            long long int num =0;
            if(isdigit(s[i])){
                while(i<s.size() && isdigit(s[i])){
                num = num*10 + (s[i] - '0');
                i++;
                }
            i--;
            sum += num *sign;
            sign = 1;
            }
            else if(s[i] == '('){
                st.push({sum,sign});
                sum = 0;
                sign =1;
            }
            else if(s[i] == ')'){
                sum = st.top().first + (st.top().second*sum);
                st.pop();
            }
            else if(s[i] == '-'){
                sign = -1*sign;
            }
        }
        return sum;

    }
};
int main() {
    Solution sol;

    cout << sol.calculate("1 + 1") << endl;              // 2
    cout << sol.calculate(" 2-1 + 2 ") << endl;          // 3
    cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;// 23

    return 0;
}
