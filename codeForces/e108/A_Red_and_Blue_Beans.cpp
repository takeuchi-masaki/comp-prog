#include <bits/stdc++.h>
using namespace std;

void ans(bool ok){
    cout << (ok?"YES\n":"NO\n");
}

void solve(){
    int r, b, d; cin >> r >> b >> d;
    int minimum = min(r, b), maximum = max(r, b);
    if( (maximum - 1) / minimum > d){
        ans(false);
    } else {
        ans(true);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}