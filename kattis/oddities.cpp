#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x; cin >> x;
    if(x&1){
        cout << x << " is odd\n";
    } else {
        cout << x << " is even\n";
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