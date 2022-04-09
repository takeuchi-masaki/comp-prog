#include <bits/stdc++.h>
using namespace std;

void solve(){
    int e, w; cin >> e >> w;
    vector<vector<int>> exercise(e, vector<int>(w));
    for(auto& vi : exercise){
        for(int& i : vi){
            cin >> i;
        }
    }

    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}