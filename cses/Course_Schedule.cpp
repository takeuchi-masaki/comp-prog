#include <bits/stdc++.h>
using namespace std;

vector<int> topsort;

void dfs(int vertex, vector<vector<int>>& adj, vector<bool>& visited){
    for(int next_vertex : adj[vertex]){
        if(visited[next_vertex]) continue;
        visited[next_vertex] = true;
        dfs(next_vertex, adj, visited);
    }
    topsort.push_back(vertex);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    vector<bool> visited(N);
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, adj, visited);
    }
    reverse(topsort.begin(), topsort.end());

    vector<int> idx(N);
    for(int i = 0; i < N; i++){
        idx[topsort[i]] = i;
    }
    for(int i = 0; i < N; i++){
        for(int j : adj[i]){
            if(idx[j] <= idx[i]){
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for(int i : topsort){
        cout << i + 1 << ' ';
    }
    cout << '\n';
}