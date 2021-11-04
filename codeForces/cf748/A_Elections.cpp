#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    int necA = max(b, c)+1,
        necB = max(a, c)+1,
        necC = max(a, b)+1;
    cout << max(necA-a, 0) << ' ' << max(necB-b, 0) 
         << ' ' << max(0, necC-c) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}