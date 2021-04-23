#include <bits/stdc++.h>
using namespace std;

int main(){
    // left -> down greedy bfs?
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector< vector<int> > grid(n, vector<int>(n));
    vector<int> diag(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i][i];
        diag[i] = grid[i][i];
        // cout << diag[i] << '\n';
    }
    for(int i = 0; i < n; i++){
        int nec = diag[i]-1;
        // cout << nec << endl;
        pair<int,int> pos = {i, i};

        while(nec>0){
            if(pos.second-1>=0 && grid[pos.first][pos.second-1] == 0){
                pos.second--;
                grid[pos.first][pos.second] = diag[i];
            } else {
                pos.first++;
                grid[pos.first][pos.second] = diag[i];
            }
            nec--;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}