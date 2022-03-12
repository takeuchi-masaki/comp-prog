#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<long long>> val(n, vector<long long>(m));
    for(auto& vl : val){
        for(auto& ll : vl) cin >> ll;
    }
    
    /*
        dp[0][0] : start from 0, don't cross all the way
        dp[0][1] : start from 0, cross
        dp[1][0] : start from m-1, don't cross
        dp[1][1] : start from m-1, cross
    */
    vector<vector<long long>> dp(2, vector<long long>(2, -INF));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        long long start0 = max(dp[0][0], dp[1][1]);
        long long startm = max(dp[0][1], dp[1][0]);
        
        // start from 0
        long long mx = 0, curr = 0;
        for(int j = 0; j < m-1; j++){
            curr += val[i][j];
            mx = max(mx, curr);
        }
        dp[0][0] = start0 + mx;
        dp[0][1] = start0 + curr + val[i][m-1];

        // start from opposite side
        if(startm == -INF) continue;
        mx = 0, curr = 0;
        for(int j = m-1; j > 0; j--){
            curr += val[i][j];
            mx = max(mx, curr);
        }
        dp[1][0] = startm + mx;
        dp[1][1] = startm + curr + val[i][0];
    }
    long long ans = 0;
    for(auto& vl : dp){
        for(auto& ll : vl){
            ans = max(ans, ll);
        }
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