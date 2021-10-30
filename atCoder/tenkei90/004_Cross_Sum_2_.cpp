#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int h, w; cin >> h >> w;
    vector< vector<int> > grid(h, vector<int>(w));
    vector<int> sumH(h), sumW(w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
            sumH[i]+=grid[i][j];
            sumW[j]+=grid[i][j];
        }
    }
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << sumH[i]+sumW[j]-grid[i][j] << ' ';
        }
        cout << '\n';
    }
}