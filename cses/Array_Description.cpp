#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    vector<vector<long long>> dp(n, vector<long long>(m + 2));
    if(a[0] == 0){
        for(int j = 1; j <= m; j++){
            dp[0][j] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        if(a[i] == 0){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        } else {
            dp[i][a[i]] = dp[i - 1][a[i]] + dp[i - 1][a[i] - 1] + dp[i - 1][a[i] + 1];
            dp[i][a[i]] %= MOD;
        }
    }
    cout << (accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0LL) % MOD) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}