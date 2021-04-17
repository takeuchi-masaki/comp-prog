#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int i, int j, vector<vector<int>>& grid){
    grid[i][j]=0;
    vector<pair<int,int>> check = 
    {
        {i-1,j},
        {i+1,j},
        {i,j-1},
        {i,j+1},
        {i+1,j+1},
        {i-1,j+1},
        {i+1,j-1},
        {i-1,j-1}
    };
    for(pair<int,int> p:check){
        if(
            p.first>=0
            && p.first<grid.size()
            && p.second>=0
            && p.second<grid[0].size()
        ) {
            if(grid[p.first][p.second]==1){
                dfs(p.first,p.second,grid);
            }
        }
    }
}

void solve(int w, int h){
    vector<vector<int>> grid(h,vector<int>(w,0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
            // cout << grid[i][j] << " ";
        }
        // cout << '\n';
    }
    int res = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j]==1){
                res++;
                dfs(i,j,grid);
            }
        }
    }
    cout << res << '\n';
}

int main(){
    while(true){
        int w, h;
        cin >> w >> h;
        // cout << w << " " << h << '\n';
        if(w==0 && h==0) break;
        solve(w,h);
    }
}