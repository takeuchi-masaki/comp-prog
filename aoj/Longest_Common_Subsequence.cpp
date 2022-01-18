#include <bits/stdc++.h>
using namespace std;

void solve(){
    string x, y; cin >> x >> y;
    int n = x.size(), m = y.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(x[i] == y[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    cout << dp[n][m] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}