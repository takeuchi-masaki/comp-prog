#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e10;

int ROW, COL;
vector< vector<int> > grid, adj;
long long minTotal = INF;
int minI, minJ;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> ROW >> COL;
    grid = vector<vector<int> >(ROW, vector<int>(COL));
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cin >> grid[i][j];
        }
    }

    vector< vector< vector< vector<long long> > > > dist(ROW, vector<vector<vector<long long>>>(COL, vector<vector<long long>>(ROW, vector<long long>(COL, INF))));
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            vector< pair<int,int> > from = {
                {i-1, j},
                {i+1, j},
                {i, j-1},
                {i, j+1}
            };
            for(auto p:from){
                if(p.first < 0
                || p.second < 0
                || p.first >= ROW
                || p.second >= COL) continue;
                dist[p.first][p.second][i][j] = grid[i][j];
            }
        }
    }

    /*
        50*50*50*log(50)
        dijkstra's
            n log n
        
    */

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            
            for(int a = 0; a < ROW; a++){
                for(int b = 0; b < COL; b++){

                    for(int c = 0; c < ROW; c++){
                        for(int d = 0; d < COL; d++){
                            dist[a][b][c][d] = min(dist[a][b][c][d], dist[a][b][i][j] + dist[i][j][c][d]);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            long long curr = dist[ROW-1][0][i][j];
            curr += dist[i][j][ROW-1][COL-1];
            curr += dist[i][j][0][COL-1];
            if(curr < minTotal){
                minTotal = curr;
                minI = i, minJ = j;
            }
        }
    }

    cout << minTotal << '\n';
}