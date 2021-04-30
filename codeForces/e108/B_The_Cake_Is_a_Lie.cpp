#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    if(n*m - 1 == k){
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
    for(int i = 0; i < T; i++) {
        solve();
    }
}