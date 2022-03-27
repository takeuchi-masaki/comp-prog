#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long factmod(long long n){
    if (n >= mod) return 0;
    long long result = 1;
    for (int i = 1; i <= n; i++){
        result = (result * i) % mod;
    }
    return result;
}

void solve(){
    int n; cin >> n;
    if(n&1){
        cout << "0\n";
        return;
    }
    n /= 2;

    long long ans = factmod(n);
    ans *= ans;
    ans %= mod;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}