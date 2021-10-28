/*
ID: themasa1
TASK: castle
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > floorplan, visited;
vector<int> roomsize;

int main() {
    freopen("castle.in","r",stdin); freopen("castle.out","w",stdout);
    int COL, ROW; cin >> COL >> ROW;
    visited = floorplan = vector< vector<int> >(ROW, vector<int>(COL));
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cin >> floorplan[i][j];
        }
    }
    /*
        1 W
        2 N
        4 E
        8 S
    */
    for(int r = 0; r < ROW; r++){
        for(int c = 0; c < COL; c++){
            if(visited[r][c]) continue;
            roomsize.push_back(1);
            visited[r][c] = roomsize.size();
            vector< vector<int> > q;
            vector<int> start = {r, c};
            q.push_back(start);
            while(!q.empty()){
                vector<int> curr = q.back();
                q.pop_back();
                vector< pair<int, int> > v = {
                    {curr[0], curr[1]-1}, // W
                    {curr[0]-1, curr[1]}, // N
                    {curr[0], curr[1]+1}, // E
                    {curr[0]+1, curr[1]}  // S
                };
                for(int i = 0; i < 4; i++){
                    if(floorplan[curr[0]][curr[1]]>>i&1) continue;
                    if(v[i].first < 0 || v[i].second < 0 
                    || v[i].first >= ROW || v[i].second >= COL) continue;
                    if(visited[v[i].first][v[i].second]) continue;
                    visited[v[i].first][v[i].second] = roomsize.size();
                    vector<int> next = {v[i].first, v[i].second};
                    roomsize.back()++;
                    q.push_back(next);
                }
            }
        }
    }
    // for(int i = 0; i < ROW; i++){
    //     for(int j = 0; j < COL; j++){
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << roomsize.size() << '\n';
    cout << *max_element(roomsize.begin(), roomsize.end()) << '\n';
    int maxCombined = 0;
    pair<int, int> wall_remove;
    char direction;
    for(int c = 0; c < COL; c++){
        for(int r = ROW-1; r >= 0; r--){
            vector< pair<int, int> > v = {
                {r, c-1}, // W
                {r-1, c}, // N
                {r, c+1}, // E
                {r+1, c}  // S
            };
            if(floorplan[r][c]&1){
                if(v[0].first >= 0 
                && v[0].second >= 0
                && v[0].first < ROW 
                && v[0].second < COL
                && visited[r][c]!=visited[v[0].first][v[0].second]
                ){
                    int combined = roomsize[visited[r][c]-1] + roomsize[visited[v[0].first][v[0].second]-1];
                    if(combined > maxCombined){
                        maxCombined = combined;
                        wall_remove = {r, c};
                        direction = 'W';
                    }
                }
            }
            for(int i = 3; i > 0; i--){
                if(!floorplan[r][c]>>i&1) continue;
                pair<int, int> p = v[i];
                if(p.first < 0 || p.second < 0
                || p.first >= ROW || p.second >= COL) continue;
                if(visited[r][c] == visited[p.first][p.second]) continue;
                int combined = roomsize[visited[r][c]-1] + roomsize[visited[p.first][p.second]-1];
                if(combined > maxCombined){
                    maxCombined = combined;
                    wall_remove = {r, c};
                    switch (i){
                        case 1: direction = 'N'; break;
                        case 2: direction = 'E'; break;
                        case 3: direction = 'S'; break;
                        default: break;
                    }
                }
            }
        }
    }
    cout << maxCombined << '\n';
    cout << wall_remove.first+1 << ' ' << wall_remove.second+1 
         << ' ' << direction << '\n';
    return 0;
}