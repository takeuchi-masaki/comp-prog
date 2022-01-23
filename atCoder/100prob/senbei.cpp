#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int r, c; cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for(int flip = 0; flip < (1<<r); flip++){
        vector<bool> fliprow(r);
        for(int bit = 0; bit < r; bit++){
            if(flip>>bit&1){
                fliprow[bit] = true;
            }
        }

        int curr = 0;
        for(int col = 0; col < c; col++){
            
        }
    }
}