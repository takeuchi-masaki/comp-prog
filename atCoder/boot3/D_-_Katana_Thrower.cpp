#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, h; cin >> n >> h;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int mx_wield = *max_element(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    for(int i : b){
        if(i <= mx_wield || h <= 0) break;
        ans++;
        h -= i;
    }

    if(h > 0){
        ans += (h + mx_wield - 1) / mx_wield;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}