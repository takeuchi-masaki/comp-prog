#include <bits/stdc++.h>
using namespace std;

string s;
int cnt = 0;
const int N = 7;
vector<vector<bool>> visited(N, vector<bool>(N, false));
vector<char> symbols = { 'D', 'U', 'L', 'R' };
map<char, int> idx;

void dfs(int currI, int currJ, string & path){
    if(path.size() == 48){
        if(currI != N-1 || currJ != 0) return;
        cnt++;
        return;
    }
    vector<pair<int,int>> directions = {
        {currI-1, currJ},
        {currI+1, currJ},
        {currI, currJ-1},
        {currI, currJ+1}
    };
    if(s[path.size()] == '?'){
        for(int i = 0; i < 4; i++){
            auto p = directions[i];
            if(p.first < 0 
            || p.second < 0
            || p.first >= N
            || p.second >= N){
                continue;
            }
            if(visited[p.first][p.second]) continue;
            visited[p.first][p.second] = true;
            path.push_back(symbols[i]);
            dfs(p.first, p.second, path);
            visited[p.first][p.second] = false;
            path.pop_back();
        }
        return;
    }
    char letter = s[path.size()];
    auto p = directions[idx[letter]];
    if(p.first < 0 
    || p.second < 0
    || p.first >= N
    || p.second >= N){
        return;
    }
    if(visited[p.first][p.second]) return;
    visited[p.first][p.second] = true;
    path.push_back(symbols[idx[letter]]);
    dfs(p.first, p.second, path);
    visited[p.first][p.second] = false;
    path.pop_back();
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;
    string path = "";
    visited[0][0] = true;
    for(int i = 0; i < 4; i++){
        idx[symbols[i]] = i;
    }
    dfs(0, 0, path);
}