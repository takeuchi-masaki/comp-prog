#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> in_degree(n), ways(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    queue<int> q;
    ways[0] = 1;
    for(int i = 0; i < n; i++){
        if(!in_degree[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int next : adj[curr]){
            ways[next] += ways[curr];
            ways[next] %= MOD;
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    cout << ways[n - 1] << '\n';
}