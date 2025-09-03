// Divide Two integers without using multiplication and Division operators 
// divident = 22
// divisor = 3 
//3+3+3+3+3+3+3 hence ans = 7
// range[-2pow(32),2pow(31)-1]
#include<bits/stdc++.h>
using namespace std;
// int sum =0;
// int cnt =0;
// while(sum+divisor<=dividend){
//     cnt++;
//     sum +=divisor;
// }
// return cnt;
int divide2(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX; // only true overflow case

    bool sign = (dividend >= 0) == (divisor >= 0);

    long long n = llabs((long long)dividend);
    long long d = llabs((long long)divisor);
    long long ans = 0;

    while (n >= d) {
        long long temp = d, multiple = 1;
        while (n >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        n -= temp;
        ans += multiple;
    }

    ans = sign ? ans : -ans;
    if (ans > INT_MAX) return INT_MAX;
    if (ans < INT_MIN) return INT_MIN;

    return (int)ans;
}

// tc- log2(n)*log2(n) approximate measure
//sc -0(1)


int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    bool sign = true;
    // for negative 
    if(dividend >=0 && divisor <0) sign = false;
    if(dividend <0 && divisor >=0) sign = false;

    long n = abs(dividend);
    long d = abs(divisor);
    divisor = abs(divisor);
    long quotient = 0;
    while(n >= d){
        int cnt =0;
        // while(n>=d*pow(2,cnt+1))
        while(n >= (d<< (cnt+1))){ 
            cnt++;
        }
        quotient += (1<<cnt);
        n = n-(d*(1<<cnt));
    }
    if((quotient == (1<<31)) && sign) {
        return INT_MAX;
    }
    if((quotient == (1<<31)) && !sign) return INT_MIN;
    return sign?quotient :-quotient;
}
int main(){
    int a,b;
    cin>>a>>b;
    int ans = divide(a,b);
}