#include <bits/stdc++.h>
using namespace std;

struct Node{
    int index, weight;
    bool operator< (const Node& n2) const {
        if(this->weight == n2.weight) return this->index < n2.index;
        return this->weight < n2.weight;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n = 5;
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k], dist[k][j]);
                }
            }
        }
    }
}