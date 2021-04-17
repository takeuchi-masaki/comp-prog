#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin >> n;
    if(n&1){
        cout << "Odd\n";
    } else {
        n>>=1;
        if(n&1){
            cout << "Same\n";
        } else {
            cout << "Even\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}