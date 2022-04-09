#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;
    long long sum = 0;
    for(int i = 1; i < n; i++){
        long long curr1 = abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
        long long curr2 = abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]);
        sum += min(curr1, curr2);
    }
    cout << sum << '\n';
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