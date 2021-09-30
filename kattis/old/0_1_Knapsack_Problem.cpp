#include <bits/stdc++.h>
using namespace std;

// int dp[105][10005];

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i] >> w[i];
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j <= W; j++){
    //         if(w[i] > j) {
    //             dp[i+1][j] = dp[i][j];
    //         } else {
    //             dp[i+1][j] = max(dp[i][j-w[i]] + v[i], dp[i][j]);
    //         }
    //     }
    // }
    // cout << dp[N][W] << endl;
    vector<int> dp_prev(W+1, 0), dp_next(W+1, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= W; j++){
            if(w[i] > j) {
                dp_next[j] = dp_prev[j];
            } else {
                dp_next[j] = max(dp_prev[j], dp_prev[j-w[i]] + v[i]);
            }
        }
        dp_prev = dp_next;
    }
    cout << dp_next[W] << endl;
}