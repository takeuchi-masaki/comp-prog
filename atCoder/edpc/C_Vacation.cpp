#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> happy(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> happy[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = happy[0][0],
    dp[0][1] = happy[0][1],
    dp[0][2] = happy[0][2];
    for(int day = 1; day < n; day++){
        for(int task = 0; task < 3; task++){
            dp[day][task] = max(dp[day - 1][(task + 1) % 3],
                                dp[day - 1][(task + 2) % 3])
                            + happy[day][task];
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
}