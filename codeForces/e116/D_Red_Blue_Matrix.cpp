#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m; cin >> n >> m;
    vector< vector<int> > grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    vector< vector<int> > minleft, minright, maxleft, maxright;
    minleft = minright = maxleft = maxright = vector< vector<int> >(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        minleft[i][0] = grid[i][0];
        maxleft[i][0] = grid[i][0];
        for(int j = 1; j < m; j++){
            minleft[i][j] = min(minleft[i][j-1], grid[i][j]);
            maxleft[i][j] = max(maxleft[i][j-1], grid[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        minright[i][m-1] = grid[i][m-1];
        maxright[i][m-1] = grid[i][m-1];
        for(int j = m-2; j >= 0; j--){
            minright[i][j] = min(minright[i][j+1], grid[i][j]);
            maxright[i][j] = max(maxright[i][j+1], grid[i][j]);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}