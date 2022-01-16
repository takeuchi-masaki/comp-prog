#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, INF));
    map<int,int> val_cnt;
    queue<pair<int,int>> q;
    val_cnt[n + m - 2] = min(n*m, 4);
    vector<pair<int,int>> corners = {
        {0, 0},
        {n - 1, 0},
        {0, m - 1},
        {n - 1, m - 1}
    };
    for(auto p : corners){
        auto [i, j] = p;
        q.push(p);
        grid[i][j] = 0;
    }
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        vector<pair<int,int>> directions = {
            {i - 1, j},
            {i + 1, j},
            {i, j - 1},
            {i, j + 1}
        };
        for(auto [nextI, nextJ] : directions){
            if(nextI < 0
            || nextJ < 0
            || nextI >= n
            || nextJ >= m) continue;
            if(grid[i][j] + 1 >= grid[nextI][nextJ]) continue;
            grid[nextI][nextJ] = grid[i][j] + 1;
            val_cnt[n + m - 2 - grid[nextI][nextJ]]++;
            q.push({nextI, nextJ});
        }
    }
    int cnt = 0;
    for(auto p : val_cnt){
        for(int i = 0; i < p.second && cnt < n*m; i++, cnt++){
            cout << p.first << ' ';
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}