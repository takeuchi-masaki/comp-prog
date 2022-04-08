#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<long long> a(n + 1);
    a[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= i + 6 && j <= n; j++){
            a[j] += a[i];
            if(a[j] > MOD) a[j] %= MOD;
        }
    }
    cout << a[n] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}