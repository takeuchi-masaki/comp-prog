#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin >> n;
    long long ans = 1;
    while(n % 2 == 0){
        n>>=1;
        ans<<=1;
    }
    if(n == 1){
        cout << "-1\n";
        return;
    }
    if(n/2 - ans >= 0){
        cout << (ans<<1) << '\n';
    } else {
        cout << n << '\n';
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}