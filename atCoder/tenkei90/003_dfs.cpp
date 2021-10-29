#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > adj;
vector<bool> visited, visited2;
int maxLen = 0, maxID;

void dfs(int currNode, int currLen){
    if(currLen > maxLen){
        maxLen = currLen;
        maxID = currNode;
    }
    for(int next:adj[currNode]){
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next, currLen+1);
        visited[next] = false;
    }
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    adj = vector< vector<int> >(n, vector<int>());
    for(int i = 1; i < n; i++){
        int from, to; cin >> from >> to;
        from--, to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    visited = vector<bool>(n);
    visited[0] = true;
    dfs(0, 1);

    visited.clear();
    visited[maxID] = true;
    dfs(maxID, 1);
    
    cout << maxLen << endl;
}