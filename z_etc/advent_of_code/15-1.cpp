#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    vector<string> grid;
    string line;
    while(getline(cin, line)) grid.push_back(line);
    vector<vector<int>> cost(grid.size(), vector<int>(grid[0].size()));
    int n = grid.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cost[i][j] = grid[i][j] - '0';
        }
    }

    // dijkstra's
    const int INF = 1e9;
    vector<vector<int>> travel_cost(n, vector<int>(n, INF));
    travel_cost[0][0] = 0;
    set<pair<int, pair<int,int>>> pq; // currCost, coord
    pq.insert(make_pair(0, make_pair(0, 0)));
    while(!pq.empty()){
        auto& [i, j] = pq.begin()->second;
        pq.erase(pq.begin());
        vector<pair<int,int>> directions = {
            {i - 1, j},
            {i + 1, j},
            {i, j - 1},
            {i, j + 1}
        };
        for(auto& p : directions){
            auto& [next_i, next_j] = p;
            if(next_i < 0
            || next_j < 0
            || next_i >= n
            || next_j >= n) continue;
            if(travel_cost[i][j] + cost[next_i][next_j] >= travel_cost[next_i][next_j]) continue;
            travel_cost[next_i][next_j] = travel_cost[i][j] + cost[next_i][next_j];
            pq.insert(make_pair(travel_cost[next_i][next_j], p));
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << travel_cost[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << travel_cost[n - 1][n - 1] << '\n';
}