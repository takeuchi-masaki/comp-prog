#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if(sum == 0){
        cout << "0\n";
        return;
    }

    long long mx = *max_element(a.begin(), a.end());
    sum -= mx;
    if(sum >= mx){
        cout << "1\n";
    } else {
        cout << mx - sum << '\n';
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