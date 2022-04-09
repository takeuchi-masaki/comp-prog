#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> grid(n);
    for(string& s : grid) cin >> s;

    int mx_diag = 0, cnt1 = 0;
    for(int col = 0; col < n; col++){
        int curr = 0;
        for(int row = 0; row < n; row++){
            if(grid[row][(col + row) % n] == '1') curr++;
        }
        mx_diag = max(mx_diag, curr);
        cnt1 += curr;
    }
    
    cout << (n - mx_diag) + (cnt1 - mx_diag) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}