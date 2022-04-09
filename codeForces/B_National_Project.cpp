#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, g, b; cin >> n >> g >> b;
    if(n <= g || g >= b){
        cout << n << '\n';
    } else {
        long long g_nec = (n + 1) / 2;
        long long cycles = (g_nec + g - 1) / g;
        long long ans = (cycles - 1) * (g + b);
        long long rem = g_nec - (cycles - 1) * g;
        ans += rem;
        cout << max(n, ans) << '\n';
    }
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