#include <bits/stdc++.h>
using namespace std;

int COLOR_CNT = 1e5 + 1;

void solve(){
    int n, m; cin >> n >> m;
    vector<long long> r_sum(COLOR_CNT), c_sum(COLOR_CNT), cnt(COLOR_CNT);
    vector<vector<int>> color(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> color[i][j];
            r_sum[color[i][j]] += i;
            c_sum[color[i][j]] += j;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}