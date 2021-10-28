#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; i++){
        cin >> grid[i];
    }
    vector< vector<int> > dp(h, vector<int>(w, INF));
    dp[0][0] = (grid[0][0]=='#');
    for(int i = 1; i < h; i++){
        dp[i][0] = dp[i-1][0] + (grid[i][0]!=grid[i-1][0]);
    }
    for(int j = 1; j < w; j++){
        dp[0][j] = dp[0][j-1] + (grid[0][j]!=grid[0][j-1]);
    }

    for(int i = 1; i < h; i++){
        for(int j = 1; j < w; j++){
            dp[i][j] = min(dp[i-1][j]+(grid[i][j]!=grid[i-1][j]), 
                        dp[i][j-1]+(grid[i][j]!=grid[i][j-1]));
        }
    }

    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    if(grid[h-1][w-1]=='#') dp[h-1][w-1]++;
    cout << dp[h-1][w-1]/2 << '\n';
}