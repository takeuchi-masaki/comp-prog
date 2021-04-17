#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void add(int& a, int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for(int i = 0; i <= n; i++) dp[i][1]=1;
    for(int i = 0; i <= k; i++) dp[0][i]=1;
    for(int remK = 2; remK <= k; remK++){
        for(int planes = 1; planes <= n; planes++){
            add(dp[planes][remK], dp[n-planes][remK-1]+dp[planes-1][remK]);
            // dp[planes][remK] = ( dp[n-planes][remK-1] + dp[planes-1][remK] )%mod;
        }
    }
    // alt, use recursive helper
    // ll ret = call(front - 1, k) + call(n - front, k - 1);
    cout << dp[n][k] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}