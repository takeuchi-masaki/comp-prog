#include <bits/stdc++.h>
using namespace std;

struct triple{
    int l, r, i;
};

void solve(){
    int n, l; cin >> n >> l;
    map<string, triple> m;

    for(int i = 0; i < n; i++){
        string ss; cin >> ss;
        for(int j = 0; j < l - 1; j++){
            m[ss.substr(j, 2)] = {j, j + 1, i};
        }
        for(int j = 0; j < l - 2; j++){
            m[ss.substr(j, 3)] = {j, j + 2, i};
        }
    }
    
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}