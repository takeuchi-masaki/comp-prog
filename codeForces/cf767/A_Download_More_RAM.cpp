#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int,int>> ab(n);
    for(auto& [a, b] : ab) cin >> a;
    for(auto& [a, b] : ab) cin >> b;
    sort(ab.begin(), ab.end());

    int ans = k;
    for(auto [a, b] : ab){
        if(a > ans) break;
        ans += b;
    }
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