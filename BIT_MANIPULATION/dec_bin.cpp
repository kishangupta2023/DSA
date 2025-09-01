// Binary to decimal 

#include<bits/stdc++.h>
using namespace std;
string f(int n){
    string res = "";
    while(n != 1){
        if(n%2 == 1) res +='1';
        else res +='0';
        n = n/2;
    }
    res += '1';
    reverse(res.begin(),res.end());
    return res;
}
//tc -> log(2)(n) here 2 is base 
//sc -> log(2)(n)

int convertToDecimal(string &s){
    int len = s.size();
    int num = 0;
    int p2=1;
    for(int i = len-1;i>=0;i--){
        if(s[i] == '1'){
            num = num + p2;
        }
        p2 = p2*2;
    }
    return num;
    //tc-o(len)
    //sc-0(1)
}
int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;

    // string s;
    // cin>>s;
    // cout<<convertToDecimal(s)<<endl;
    return 0;
}