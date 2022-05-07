#include <bits/stdc++.h>
using namespace std;

void solve(){
    int r, c; cin >> r >> c;
    vector<string> grid(r);
    for(int i = 0; i < r; i++){
        cin >> grid[i];
        reverse(grid[i].begin(), grid[i].end());
    }
    for(int j = 0; j < c; j++){
        for(int i = 0; i < r/2; i++){
            char temp = grid[i][j];
            grid[i][j] = grid[r-1-i][j];
            grid[r-1-i][j] = temp;
        }
    }
    for(int i = 0; i < r; i++){
        cout << grid[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Test " << i << '\n';
        solve();
    }
}