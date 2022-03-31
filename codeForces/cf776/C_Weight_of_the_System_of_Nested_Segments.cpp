#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    map<int, int> xCoord_to_idx;
    vector<pair<int, int>> vp(m);
    for(int i = 1; i <= m; i++){
        auto& [w, x] = vp[i - 1];
        cin >> x >> w;
        xCoord_to_idx[x] = i;
    }
    sort(vp.begin(), vp.end());

    vector<pair<int, int>> ans;
    for(int i = 0; i < 2*n; i++){
        ans.push_back({vp[i].second, vp[i].first});
    }
    sort(ans.begin(), ans.end());

    int total_weight = 0;
    for(int i = 0; i < n; i++){
        total_weight += ans[i].second + ans[2*n - 1 - i].second;
    }
    cout << total_weight << '\n';

    for(int i = 0; i < n; i++){
        cout << xCoord_to_idx[ans[i].first] << ' ' 
             << xCoord_to_idx[ans[2*n - 1 - i].first] << '\n';
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