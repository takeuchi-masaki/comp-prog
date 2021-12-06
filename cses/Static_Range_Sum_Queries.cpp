#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<long long> val(n), pref(n + 1);
    for(long long & i : val) cin >> i;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + val[i - 1];
    }

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
}