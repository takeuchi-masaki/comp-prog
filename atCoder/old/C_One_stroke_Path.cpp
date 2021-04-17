#include <bits/stdc++.h>

using namespace std;
const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int n, vector<bool> seen){
    bool all_visited = true;
    for(int i = 0; i < n; i++){
        if(seen[i] == false){
            all_visited = false;
            break;
        }
    }
    if(all_visited) return 1;
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(graph[v][i]==false) continue;
        if(seen[i]) continue;

        seen[i] = true;
        ret+=dfs(i, n, seen);
        seen[i] = false;
    }
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = graph[b][a] = true;
    }
    vector<bool> seen(nmax);
    seen[0] = true;
    int count = dfs(0, n, seen);
    cout << count;
}