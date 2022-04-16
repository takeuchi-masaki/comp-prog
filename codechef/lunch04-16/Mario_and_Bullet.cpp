#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y, z;
    cin >> x >> y >> z;
    int time = y/x;
    cout << max(0, z - time) << '\n';
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}