#include <bits/stdc++.h>
using namespace std;

// void printGrid(vector<vector<int> > & grid){
//     int n = grid.size();
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cout << grid[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector< vector<int> > happ(n, vector<int>(n));
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            // cout << i << ' ' << j << '\n';
            cin >> happ[i][j];
            happ[j][i] = happ[i][j];
        }
    }
    // printGrid(happ);

    // 3^n bitmask
    int ans = -1e9;
    for(int bit = 0; bit < pow(3, n); bit++){
        int pow3 = 1;
        vector<int> group(n);
        for(int i = 0; i < n; i++){
            group[i] = (bit/pow3)%3;
            pow3*=3;
        }
        int curr = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(group[i] == group[j]) curr += happ[i][j];
            }
        }
        ans = max(ans, curr);
    }
    cout << ans << '\n';
}