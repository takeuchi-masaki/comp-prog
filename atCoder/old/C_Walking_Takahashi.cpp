#include <bits/stdc++.h>
using namespace std;

long long min(long long a, long long b){
    return (a<b?a:b);
}
long long max(long long a, long long b){
    return (a>b?a:b);
}

int main(){
    long long INF = 1E18;
    long long x, k, d;
    cin >> x >> k >> d;
    // x starting pos
    // k moves
    // d distance/move
    long long res = INF;
    long long moves = min(abs(x/d),k);
    long long right = INF;
    long long left = INF;
    k-=moves;
    if(x>=0){
        x-=moves*d;
        if(k&1){
            right = x+d;
            left = x-d;
        } else {
            right = x;
            if(k>1){
                left = x - d*2;
            }
        }
    } else {
        x+=moves*d;
        if(k&1){
            right = x+d;
            left = x-d;
        } else {
            left = x;
            if(k>1){
                right = x + d*2;
            }
        }
    }
    res = min(abs(left),right);
    cout << res << endl;
}