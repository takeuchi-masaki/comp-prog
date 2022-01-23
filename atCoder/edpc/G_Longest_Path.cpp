#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> edge(n), back_edge(n);
    vector<int> in_degree(n), dist(n);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        back_edge[y].push_back(x);
        in_degree[y]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int next : edge[curr]){
            if(--in_degree[next] == 0) q.push(next);
        }

        for(int prev : back_edge[curr]){
            dist[curr] = max(dist[curr], dist[prev] + 1);
        }
    }
    // for(int i : dist) cout << i << ' ';
    // cout << '\n';
    cout << *max_element(dist.begin(), dist.end()) << '\n';
}