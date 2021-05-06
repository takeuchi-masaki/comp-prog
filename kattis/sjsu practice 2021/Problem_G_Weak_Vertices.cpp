#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n; cin >> n;
        if(n==-1) break;
        vector< vector<int> > grid(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
                // cout << grid[i][j] << ' ';
            }
            // cout << endl;
        }
        vector<bool> strong(n, false);
        for(int i = 0; i < n; i++){
            if(strong[i]) continue;
            for(int j = 0; j < n-1; j++){
                if(grid[i][j]==0) continue;
                for(int k = j+1; k < n; k++){
                    if(grid[i][k]==0) continue;
                    if(grid[j][k]==1) {
                        strong[i] = true;
                        strong[j] = true;
                        strong[k] = true;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!strong[i]){
                cout << i << ' ';
            }
        }
        cout << endl;
    }
}