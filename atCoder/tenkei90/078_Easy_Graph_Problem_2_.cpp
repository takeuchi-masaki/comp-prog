#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        if(a < b){
            adj[b].push_back(a);
        } else if(b < a){
            adj[a].push_back(b);
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 1){
            count++;
        }
    }
    cout << count << endl;
}