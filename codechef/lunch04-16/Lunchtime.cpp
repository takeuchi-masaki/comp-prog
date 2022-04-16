#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x; cin >> x;
    if(x >= 1 && x <= 4){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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