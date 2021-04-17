#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;
    vector<vector<bool>> grid(r,vector<bool>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int temp;
            cin >> temp;
            grid[i][j]=temp;
        }
    }
    int res = 0;
    for(int bit = 0; bit < (1<<r); bit++){
        // for(int i = 0; i < r; i++){
        //     if(bit&(1<<i)){
        //         for(int j = 0; j < c; j++){
        //             grid[i][j]=!grid[i][j];
        //         }
        //     }
        // }
        int curr = 0;
        for(int j = 0; j < c; j++){
            int count = 0;
            for(int i = 0; i < r; i++){
                count += grid[i][j]^bool(bit&(1<<i)); 
            }
            curr += max(count,r-count);
        }
        res = max(res,curr);
    }
    cout << res << endl;
}