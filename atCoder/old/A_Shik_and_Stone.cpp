#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; i++){
        cin >> grid[i];
    }
    int maxH = 0, maxW = 0;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(grid[i][j]=='#'){
                if(i<maxH || j<maxW){
                    cout << "Impossible\n";
                    return 0;
                }
                maxH = max(maxH, i);
                maxW = max(maxW, j);
            }
        }
    }
    cout << "Possible\n";
}