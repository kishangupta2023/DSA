// Implement Min Stack 
#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> st;  // use long long to avoid overflow
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        long long v = val;
        if(st.empty()) {
            st.push(v);
            mini = v;
        }
        else if(v >= mini) {
            st.push(v);
        }
        else {
            st.push(2*v - mini); // encoded
            mini = v;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) {
            // restore old min
            mini = 2*mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long x = st.top();
        if(x >= mini) return (int)x;
        else return (int)mini;  // decode
    }
    
    int getMin() {
        return (int)mini;
    }
    // tc-0(1)
    //sc-0(n)
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    
    return 0;
}