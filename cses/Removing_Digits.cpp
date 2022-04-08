#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve(){
    int n; cin >> n;
    vector<int> dp(n + 1, INF);
    dp[n] = 0;

    for(int i = n; i > 0; i--){
        if(dp[i] == INF) continue;
        string s = to_string(i);
        for(char c : s){
            int digit = c - '0';
            int sub = i - digit;
            if(sub >= 0){
                dp[sub] = min(dp[sub], dp[i] + 1);
            }
        }
    }
    assert(dp[0] != INF);
    cout << dp[0] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}