#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long x, y; cin >> x >> y;
    // 𝑛 mod 𝑥 = 𝑦 mod 𝑛
    long long n;
    if(x > y){
        n = x+y;
    }
    // y >= x, in between x,y
    if(x <= y){
        n = y-(y%x/2);
    }
    // cout << n%x << ' ' << y%n << '\n';
    cout << n << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}