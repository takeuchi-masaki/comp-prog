#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin >> n;
    int ans = 0;
    long long a_sq = 1;
    for(long long a = 3; ; a++){
        a_sq = a * a;
        if(a_sq > 2*n) break;
        if(a_sq&1){
            long long b = a_sq / 2;
            long long c = b + 1;
            if(a_sq + b*b == c*c) {
                // cout << a << ' ' << b << ' ' << c << '\n';
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}