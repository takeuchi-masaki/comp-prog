// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> d,f;

void dfs(int index, int& currTime){
    // if(d[index]!=-1) return;
    d[index] = ++currTime;
    vector<int> adjacent = adj[index];
    for(int i : adjacent){ 
        if(d[i]==-1){
            dfs(i,currTime);
        }
    }
    f[index] = ++currTime;
}

int main(){
    int n; // num vertices
    cin >> n;
    adj = vector<vector<int>> (n+1,vector<int>(0));
    for(int i = 1; i <= n; i++){
        int u, k;
        cin >> u >> k;
        for(int j = 0; j < k; j++){
            int edge;
            cin >> edge;
            adj[u].push_back(edge);
        }
    }
    d = vector<int> (n+1,-1);
    f = vector<int> (n+1);
    int currTime = 0;
    for(int i = 1; i <= n; i++){
        if(d[i]==-1) dfs(i, currTime);
    }
    for(int i = 1; i <= n; i++){
        cout << i << " " << d[i] << " " << f[i] << '\n';
    }
}