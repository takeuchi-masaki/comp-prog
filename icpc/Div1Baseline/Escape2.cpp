#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve(){
    int k, w, h; cin >> k >> w >> h;
    vector<int> klingon(255);
    for(int i = 0; i < k; i++){
        char c;
        int time;
        cin >> c >> time;
        klingon[c] = time;
    }
    vector<string> grid(h);
    for(string& s : grid) cin >> s;
    pair<int,int> start = {-1, -1};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == 'E') {
                start = {i,j};
                break;
            }
        }
        if(start.first == i) break;
    }

    vector<vector<int>> dist(h, vector<int>(w, INF));
    set<pair<int, pair<int,int>>> pq;
    pq.insert({0, start});
    while(!pq.empty()){
        auto [currW, p] = *pq.begin();
        auto [i, j] = p;
        pq.erase(pq.begin());

        vector<pair<int,int>> directions = {
            {i - 1, j},
            {i + 1, j},
            {i, j - 1},
            {i, j + 1}
        };
        for(auto [nextI, nextJ] : directions){
            if(nextI < 0
            || nextJ < 0
            || nextI >= h
            || nextJ >= w){
                cout << currW << '\n';
                return;
            }
            int cost = klingon[grid[nextI][nextJ]];
            if(cost + currW >= dist[nextI][nextJ]) continue;
            dist[nextI][nextJ] = cost + currW;
            pq.insert({dist[nextI][nextJ], {nextI, nextJ}});
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}