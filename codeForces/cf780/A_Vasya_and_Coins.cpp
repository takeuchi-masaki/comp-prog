#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long a, b; cin >> a >> b;
    if(a == 0){
        cout << "1\n";
        return;
    }
    b += a/2;
    a %= 2;
    cout << b*2 + a + 1 << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}