#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, w; cin >> h >> w;
    vector< vector<int> > grid(h, vector<int>(w));
    int min_ele = 1e9;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
            min_ele = min(min_ele, grid[i][j]);
        }
    }
    int res = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            res += grid[i][j]-min_ele;
        }
    }
    cout << res << '\n';
}