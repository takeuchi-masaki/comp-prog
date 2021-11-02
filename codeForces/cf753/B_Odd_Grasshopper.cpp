#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long x0, n; cin >> x0 >> n;
    long long rem = n%4;
    // if(rem == 0){
    //     cout << x0 << '\n';
    //     return;
    // }
    long long skip = n-rem+1;
    for(int i = 0; i < rem; i++){
        if(x0&1){
            x0 += skip+i;
        } else {
            x0 -= skip+i;
        }
    }
    cout << x0 << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}