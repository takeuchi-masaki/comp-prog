#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y;
    cin >> x >> y;
    if(y < x || y % x != 0) {
        cout << "0 0\n";
        return;
    }
    if(y == x) {
        cout << "1 1\n";
        return;
    }
    cout << "1 " << y / x << "\n";
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
}