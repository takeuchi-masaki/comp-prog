#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector< vector<int> > adj;
void dfs(int curr, vector<bool> &visited){
    for(int i:adj[curr]){
        if(visited[i]) continue;
        visited[i] = true;
        ans++;
        dfs(i, visited);
    }
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int m; cin >> n >> m;
    adj = vector< vector<int> > (n, vector<int>());
    ans = 0;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    for(int i = 0; i < n; i++){
        vector<bool> visited(n,false);
        visited[i] = true;
        ans++;
        dfs(i, visited);
    }
    cout << ans << endl;
}