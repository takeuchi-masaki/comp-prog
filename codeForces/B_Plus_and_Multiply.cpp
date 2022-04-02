#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, a, b; cin >> n >> a >> b;
    long long x = 1;
    while(x <= n){
        if((n - x) % b == 0){
            cout << "Yes\n";
            return;
        }
        if(a == 1) break;
        x *= a;
    }
    cout << "No\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}