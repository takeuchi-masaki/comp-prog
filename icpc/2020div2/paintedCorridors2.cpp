#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, r, b, y;
    cin >> n >> m >> r >> b >> y;
    r--, b--, y--;
    vector<vector<int>> corridor_nec(n, vector<int>(n, -1));
    vector<int> junction(n);
    
    unordered_map<char, int> colorKey = {
        {'R', 4},
        {'B', 2},
        {'Y', 1},
        {'O', 5},
        {'P', 6},
        {'G', 3},
        {'X', 0}
    };
    for(int i = 0; i < m; i++){
        int junc1, junc2;
        char color;
        cin >> junc1 >> junc2 >> color;
        junc1--, junc2--;
        corridor_nec[junc1][junc2] = colorKey[color];
        corridor_nec[junc2][junc1] = corridor_nec[junc1][junc2];
    }

    // bfs
    queue<pair<int,int>> q; 
    // color, junction of initial robots
    q.push({colorKey['R'], r});
    q.push({colorKey['B'], b});
    q.push({colorKey['Y'], y});
    while(!q.empty()){
        auto [c, j] = q.front(); q.pop();
        junction[j] |= c;

        for(int i = 0; i < n; i++){
            if(corridor_nec[j][i] == -1) continue;
            if(corridor_nec[j][i] == 0){
                for(int col = 0; col < 3; col++){
                    if((junction[i]>>col&1) || !(junction[j]>>col&1)) continue;
                    q.push({(1<<col), i});
                }
                junction[i] |= junction[j];
                continue;
            }

            bool ok = true;
            for(int col = 0; col < 3; col++){
                // need color and don't have color
                if((corridor_nec[j][i]>>col&1) && !(junction[j]>>col&1)){
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;
            for(int col = 0; col < 3; col++){
                // if the corridor color isn't already available at the next junction
                if((corridor_nec[j][i]>>col&1) && !(junction[i]>>col&1)){
                    q.push({(1<<col), i});
                }
            }
            junction[i] |= corridor_nec[j][i];
        }
    }

    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(corridor_nec[i][j] < 1) continue;
            for(int col = 0; col < 3; col++){
                // if either junction doesn't have a necessary corridor color
                if(corridor_nec[i][j]>>col&1){
                    if(!(junction[i]>>col&1)
                    || !(junction[j]>>col&1)){
                        ok = false;
                        break;
                    }
                }
            }
        }
    }
    cout << (ok ? "1" : "0") << '\n';
}