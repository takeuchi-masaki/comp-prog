#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, p;
    cin >> n >> p;
    vector<vector<int>> vvi(n, vector<int>(p));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            cin >> vvi[i][j];
        }
        sort(vvi[i].begin(), vvi[i].end());
    }
    vector<vector<long long>> ans(n, vector<long long>(2));
    ans[0][0] = 2 * vvi[0].back() - vvi[0][0];
    ans[0][1] = vvi[0].back();
    for(int i = 1; i < n; i++){
        ans[i][0] = min(
            abs(vvi[i - 1][0] - vvi[i].back()) + ans[i - 1][0],
            abs(vvi[i - 1].back() - vvi[i].back()) + ans[i - 1][1]
        ) + (vvi[i].back() - vvi[i][0]);
        ans[i][1] = min(
            abs(vvi[i - 1][0] - vvi[i][0]) + ans[i - 1][0],
            abs(vvi[i - 1].back() - vvi[i][0]) + ans[i - 1][1]
        ) + (vvi[i].back() - vvi[i][0]);
    }
    cout << min(ans.back()[0], ans.back()[1]) << '\n';
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}