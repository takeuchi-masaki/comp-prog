#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct coord{
    int i, j, k;
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int l, r, c;
    while(cin >> l >> r >> c){
        if(l == 0) break;
        vector<vector<string>> grid(l, vector<string>(r));
        for(int i = 0; i < l; i++){
            for(string& s : grid[i]) cin >> s;
        }
        coord start;
        bool ok = false;
        for(int i = 0; i < l && !ok; i++){
            for(int j = 0; j < r && !ok; j++){
                for(int k = 0; k < c && !ok; k++){
                    if(grid[i][j][k] == 'S'){
                        ok = true;
                        start = {i,j,k};
                    }
                }
            }
        }
        
        vector<vector<vector<int>>> dist(l, vector<vector<int>>(r, vector<int>(c, INF)));
        dist[start.i][start.j][start.k] = 0;
        queue<coord> q;
        q.push(start);
        ok = false;
        while(!q.empty()){
            auto [level, row, col] = q.front();
            q.pop();
            if(grid[level][row][col] == 'E'){
                cout << "Escaped in " << dist[level][row][col] << " minute(s).\n";
                ok = true;
                break;
            }
            vector<coord> directions = {
                {level - 1, row, col},
                {level + 1, row, col},
                {level, row - 1, col},
                {level, row + 1, col},
                {level, row, col - 1},
                {level, row, col + 1}
            };
            for(coord next : directions){
                auto [nextI, nextJ, nextK] = next;
                if(nextI < 0
                || nextI >= l
                || nextJ < 0
                || nextJ >= r
                || nextK < 0
                || nextK >= c) continue;
                if(grid[nextI][nextJ][nextK] == '#') continue;
                if(dist[nextI][nextJ][nextK] < INF) continue;
                dist[nextI][nextJ][nextK] = dist[level][row][col] + 1;
                q.push(next);
            }
        }
        if(!ok){
            cout << "Trapped!\n";
        }
    }
}