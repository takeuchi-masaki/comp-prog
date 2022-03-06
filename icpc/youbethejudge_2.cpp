#include <bits/stdc++.h>
using namespace std;

void ans(bool ok){
    cout << (ok ? "1\n" : "0\n");
}

int n, pow_n2;
vector<vector<int>> grid;
unordered_set<int> nums_used;

bool check_surrounding(int i, int j){
    vector<vector<pair<int,int>>> types = {
        {
            {i, j+1},   // X 1
            {i+1, j},   // 1
        },
        {
            {i, j+1},   // X 1
            {i+1, j+1}  //   1
        },
        {
            {i+1, j},   //   X
            {i+1, j-1}, // 1 1
        },
        {
            {i+1, j},   // X
            {i+1, j+1}  // 1 1
        }
    };
    for(auto vp : types){
        bool bad = false;
        for(auto[I, J] : vp){
            if(I >= pow_n2
            || J < 0
            || J > pow_n2
            || grid[I][J] != grid[i][j]){
                bad = true;
                break;
            }
        }
        if(bad) continue;
        grid[i][j] = -1;
        for(auto[I, J] : vp){
            grid[I][J] = -1;
        }
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    pow_n2 = 1<<n;
    grid.resize(pow_n2, vector<int>(pow_n2)); // n^2 * n^2 grid
    for(int i = 0; i < pow_n2; i++){
        for(int j = 0; j < pow_n2; j++){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < pow_n2; i++){
        for(int j = 0; j < pow_n2; j++){
            if(grid[i][j] == -1) continue;
            if(!nums_used.insert(grid[i][j]).second){
                ans(false);
                return 0;
            }
            if(grid[i][j] == 0){
                grid[i][j] = -1;
                continue;
            }
            if(!check_surrounding(i, j)){
                ans(false);
                return 0;
            }
        }
    }
    if(!nums_used.count(0)){
        ans(false);
    } else {
        ans(true);
    }
}