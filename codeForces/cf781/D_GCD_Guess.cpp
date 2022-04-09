#include <bits/stdc++.h>
using namespace std;

void solve(int hidden){
    long long l = 1, r = 1e9 + 1;
    while(r - l > 1){
        long long m = l + (r - l)/2;
        long long a, b;
        long long response = gcd(a + hidden, b + hidden);
        
    }
    

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1e6;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve(i);
    }
}