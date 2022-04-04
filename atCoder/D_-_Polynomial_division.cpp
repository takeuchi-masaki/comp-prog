#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), c(n + m + 1);
    for(int& i : a) cin >> i;
    for(int& i : c) cin >> i;

    vector<int> b(m + 1), rem = c;
    for(int x = m; x >= 0; x--){
        b[x] = rem[x + n] / a[n];
        for(int i = 0; i <= n; i++){
            rem[x + i] -= b[x] * a[i];
        }
    }
    for(int i : b) cout << i << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}