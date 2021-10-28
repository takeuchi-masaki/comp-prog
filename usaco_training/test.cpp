#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int ROW, COL;

struct State{
    public:
    int r, c, idx;
    State(int rr, int cc, int idxx){
        this->r = rr;
        this->c = cc;
        this->idx = idxx;
    }
};

bool dfs(int i, int j, int idx, string word){
    if(idx == word.size()) return true;
    vector< pair<int, int> > nextCoords = {
        {i-1, j},
        {i+1, j},
        {i, j-1},
        {i, j+1}
    };
    for(pair<int, int> p:nextCoords){
        if(p.first < 0
        || p.second < 0
        || p.first >= ROW
        || p.second >= COL) continue;
        if(grid[p.first][p.second] != word[idx]) continue;
        char c = grid[i][j];
        grid[i][j] = ' ';
        if(dfs(p.first, p.second, idx+1, word)) {
            grid[i][j] = c;
            return true;
        }
        grid[i][j] = c;
    }
    return false;
}

bool wordSearch(string word){
    ROW = grid.size(), COL = grid[0].size();
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(grid[i][j] != word[0]) continue;
            if(dfs(i, j, 1, word)) return true;
        }
    }
    return false;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int r, c, testWords;
    cin >> r >> c >> testWords;
    grid = vector<string>(r);
    for(int i = 0; i < r; i++){
        cin >> grid[i];
    }
    while(testWords--){
        string findWord;
        cin >> findWord;
        cout << findWord << ' ' << wordSearch(findWord) << '\n';
    }
}