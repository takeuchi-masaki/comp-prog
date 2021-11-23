#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<long long> weight(n), val(n);
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> val[i];
    }
    int m = 100000;
    const int INF = 1e9 + 5;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= m; j++){
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if(j - val[i] >= 0){
                dp[i + 1][j] = min(dp[i + 1][j],
                    dp[i][j - val[i]] + weight[i]);
            }
        }
    }
    int col = m;
    for(col; col >= 0; col--){
        if(dp[n][col] <= w) break;
    }
    cout << col << '\n';
}