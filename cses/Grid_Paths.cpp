#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<string> vs(n);
    for(string& s : vs) cin >> s;
    // '.' empty
    // '*' trap

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    if(vs[0][0] != '*') dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] == 0) continue;
            if(i + 1 < n && vs[i + 1][j] != '*'){
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
            if(j + 1 < n && vs[i][j + 1] != '*'){
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}