#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> grid(n);
    for(string& s : grid) cin >> s;
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1') cnt1++;
        }
    }

    vector<int> row(n), col(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            row[i] += grid[i][j] == '1';
            col[i] += grid[j][i] == '1';
        }
    }
    // int ans = 0;
    // for(int i = 0; i < n; i++){
    //     ans += abs(row[i] + col[i] - 2);
    // }
    // cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}