#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, d, e; cin >> n >> d >> e;
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    for(int i = 0; i < e; i++){
        int x, y; cin >> x >> y;
        dist[x][y] = 1;
        dist[y][x] = 1;
    }
    
    // floyd-warshall
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}