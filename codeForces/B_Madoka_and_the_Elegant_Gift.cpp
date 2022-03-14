#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> vs(n);
    for(string& s : vs) cin >> s;
    vector<vector<int>> grid(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            grid[i][j] = vs[i-1][j-1] - '0';
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int cnt = 0;
            cnt += grid[i][j];
            cnt += grid[i][j+1];
            cnt += grid[i+1][j];
            cnt += grid[i+1][j+1];
            if(cnt == 3){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}