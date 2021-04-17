#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m;
    long long x;
    cin >> n >> m >> x;
    // 1, 1+n...
    long long w = (x-1)/n;
    long long h = (x-1)%n;
    // cout << h << " " << w << "\n";
    long long res = h*m + w;
    cout << res+1 << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}