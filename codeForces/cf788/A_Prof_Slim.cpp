#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& i: a) cin >> i;
    int cnt_negative = 0, cnt_positive = 0;
    for (int& i: a) {
        if(i < 0) {
            cnt_negative++;
            i = abs(i);
        } else {
            cnt_positive++;
        }
    }
    for (int i = 0; i < cnt_negative; i++) {
        a[i] = -a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
}