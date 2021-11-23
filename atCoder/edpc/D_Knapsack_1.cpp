#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<long long> weight(n), val(n);
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> val[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, -1));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= w; j++){
            if(dp[i][j] == -1) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j + weight[i] <= w) {
                dp[i + 1][j + weight[i]] = max(dp[i + 1][j + weight[i]],
                                            dp[i][j] + val[i]);
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}