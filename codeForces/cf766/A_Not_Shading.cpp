#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, r, c; cin >> n >> m >> r >> c;
    r--, c--;
    vector<string> grid(n);

    for(string& s : grid) cin >> s;
    if(grid[r][c] == 'B'){
        cout << "0\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(grid[i][c] == 'B'){
            cout << "1\n";
            return;
        }
    }
    for(int j = 0; j < m; j++){
        if(grid[r][j] == 'B'){
            cout << "1\n";
            return;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'B'){
                cout << "2\n";
                return;
            }
        }
    }
    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}