#include <bits/stdc++.h>
using namespace std;

int maxLen = 0, maxLenNode;

void dfs(int currNode, int currLen, vector<bool>&visited, vector<vector<int> > & adj){
    if(currLen > maxLen){
        maxLen = currLen;
        maxLenNode = currNode;
    }
    for(int i:adj[currNode]){
        if(!visited[i]){
            visited[i] = true;
            dfs(i, currLen+1, visited, adj);
            visited[i] = false;
        }
    }
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector< vector<int> > adj(n, vector<int>());
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n);
    visited[0] = true;
    dfs(0, 1, visited, adj);
    visited = vector<bool>(n);
    visited[maxLenNode] = true;
    dfs(maxLenNode, 1, visited, adj);
    cout << maxLen << endl;
}