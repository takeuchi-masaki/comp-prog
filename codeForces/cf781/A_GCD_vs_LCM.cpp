#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin >> n;
    long long a = 1, b = n - 3, c = 1, d = 1;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
    // cout << "END\n";
}