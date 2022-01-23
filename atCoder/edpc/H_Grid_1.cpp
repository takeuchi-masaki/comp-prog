#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    for(string& s : grid) cin >> s;
    vector<vector<int>> dp(h, vector<int>(w));
    dp[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '#') continue;
            if(i + 1 < h && grid[i+1][j] != '#'){
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            }
            if(j + 1 < w && grid[i][j+1] != '#'){
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
            }
        }
    }
    cout << dp[h-1][w-1] << '\n';
}