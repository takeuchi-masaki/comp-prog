#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int rMax, cMax; cin >> rMax >> cMax;
    vector<string> grid(rMax);
    for(string& s : grid) cin >> s;
    deque<pair<int,int>> q;
    for(int i = 0; i < rMax - 1; i++){
        for(int j = 0; j < cMax; j++){
            if(grid[i][j] != 'V') continue;
            if(grid[i + 1][j] == 'V') continue;
            q.push_back({i, j});
        }
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop_front();
        if(p.first == rMax - 1) continue;
        if(grid[p.first + 1][p.second] == '.'){
            grid[p.first + 1][p.second] = 'V';
            q.push_back({p.first + 1, p.second});
        } else if(grid[p.first + 1][p.second] == '#'){
            if(p.second > 0 && grid[p.first][p.second - 1] == '.'){
                grid[p.first][p.second - 1] = 'V';
                q.push_back({p.first, p.second - 1});
            }
            if(p.second + 1 < cMax && grid[p.first][p.second + 1] == '.'){
                grid[p.first][p.second + 1] = 'V';
                q.push_back({p.first, p.second + 1});
            }
        }
    }

    for(string s : grid) cout << s << '\n';
}