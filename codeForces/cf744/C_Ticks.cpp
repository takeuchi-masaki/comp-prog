#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> paint(n, vector<bool>(m));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '*') grid[i][j]++;
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0) continue;
            int len = 1;
            while(true){
                if(i-len < 0 || j-len < 0 || j+len >= m) break;
                if(grid[i-len][j-len] == 0) break;
                if(grid[i-len][j+len] == 0) break;
                len++;
            }
            len--;
            if(len < k) continue;
            for(int k = 0; k <= len; k++){
                grid[i-k][j-k] = 2;
                grid[i-k][j+k] = 2;
            }
        }
    }

    bool ok = true;
    for(int i = 0; i < n && ok; i++){
        for(int j = 0; j < m && ok; j++){
            if(grid[i][j] == 1) ok = false;
        }
    }
    cout << (ok?"YES\n":"NO\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}