#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    adj[0].push_back(1);
    for(int i = 2; i <= n; i++){
        int parent; cin >> parent;
        adj[parent].push_back(i);
    }

    vector<int> child_cnt;
    for(int i = 0; i <= n; i++){
        if(adj[i].empty()) continue;
        child_cnt.push_back(adj[i].size());
    }
    sort(child_cnt.rbegin(), child_cnt.rend());

    int l = 0, r = 1e9;
    while(r - l > 1){
        int m = l + (r - l) / 2;
        long long add = 0;
        for(int i : child_cnt){
            if(i > m) add += i - m;
        }
        if(add <= m){
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}