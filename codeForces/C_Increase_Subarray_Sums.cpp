#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n), pref(n + 1), max_of_len(n + 1, -INF);
    max_of_len[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    for(int len = 1; len <= n; len++){
        for(int start = 0; start + len <= n; start++){
            max_of_len[len] = max(max_of_len[len], pref[start + len] - pref[start]);
        }
    }

    // for(int i : max_of_len) cout << i << ' ';
    // cout << '\n';
    for(int k = 0; k <= n; k++){
        int ans = 0;
        for(int len = 0; len <= n; len++){
            ans = max(ans, max_of_len[len] + x * min(k, len));
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}