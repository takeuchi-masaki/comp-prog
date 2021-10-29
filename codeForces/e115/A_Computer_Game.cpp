#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> grid(2);
    cin >> grid[0] >> grid[1];
    bool ok = true;
    for(int i = 0; i < n; i++){
        if(grid[0][i] == '1' && grid[1][i] == '1'){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}