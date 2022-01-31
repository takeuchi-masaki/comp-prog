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

    queue<pair<int,int>> q;
    q.push({colorKey['R'], r});
    q.push({colorKey['B'], b});
    q.push({colorKey['Y'], y});
    while(!q.empty()){
         = q.front();
        q.pop();
        junction[curr.junc] |= curr.color;
        for(int i = 0; i < n; i++){
            if(corridor_nec[curr.junc][i] == -1) continue;
            if(corridor_nec[curr.junc][i] == 0){
                for(int col = 0; col < 3; col++){
                    if((curr.color>>col&1) == 0) continue;
                    if((junction[i]>>col&1) == (curr.color>>col&1)) continue;
                    q.push({(1>>col), i});
                }
                continue;
            }
            bool ok = true;
            for(int col = 0; col < 3; col++){
                if(corridor_nec[curr.junc][i]>>col&1){
                    if(!(junction[curr.junc]>>col&1)) {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                for(int col = 0; col < 3; col++){
                    if((junction[i]>>col&1) == (corridor_nec[curr.junc][i]>>col&1)) continue;
                    q.push({(1>>col), i});
                }
            }
        }
    }

    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((corridor_nec[i][j] == -1)
            || (corridor_nec[i][j] == 0)) continue;
            for(int col = 0; col < 3; col++){
                if(corridor_nec[i][j]>>col&1){
                    if((!(junction[i]>>col&1))
                    && (!(junction[j]>>col&1))) ok = false;
                }
            }
        }
    }
    cout << (ok ? "1" : "0") << '\n';
}