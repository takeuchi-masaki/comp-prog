#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    int curr = -1, end = -1;
    for(int i = 0; i < n; i++){
        auto vi = adj[i];
        if(vi.size() > 2){
            cout << "-1\n";
            return;
        }
        if(vi.size() == 1){
            if(curr == -1){
                curr = i;
            } else {
                end = i;
            }
        }
    }
    if(curr != -1 && curr == end){
        cout << "2\n";
        return;
    }
    vector<int> val(n - 1, -1);
    bool two = true;
    while(curr != end){
        for(auto [next, edge] : adj[curr]){
            if(val[edge] != -1) continue;
            val[edge] = (two ? 2 : 3);
            two = !two;
            curr = next;
            break;
        }
    }

    for(int i : val) cout << i << ' ';
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