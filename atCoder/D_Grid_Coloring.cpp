#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, w, n; cin >> h >> w >> n;
    vector<pair<int,int>> color_count(n);
    for(int i = 0; i < n; i++){
        int cnt; cin >> cnt;
        color_count[i] = {cnt, i + 1};
    }
    sort(color_count.begin(), color_count.end());
    vector<vector<int>> grid(h, vector<int>(w));
    for(int row = 0; row < h; row++){
        if(row % 2 == 0){
            for(int col = 0; col < w; col++){
                grid[row][col] = color_count.back().second;
                color_count.back().first--;
                if(color_count.back().first == 0) color_count.pop_back();
            }
        } else {
            for(int col = w - 1; col >= 0; col--){
                grid[row][col] = color_count.back().second;
                color_count.back().first--;
                if(color_count.back().first == 0) color_count.pop_back();
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int col : grid[i]){
            cout << col << ' ';
        }
        cout << '\n';
    }
}