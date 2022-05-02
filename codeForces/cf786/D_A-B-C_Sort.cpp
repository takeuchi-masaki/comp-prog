#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    vector<int> ans;
    int idx = 0;
    if(n & 1) {
        ans.push_back(a[0]);
        idx++;
    }
    while(idx < n){
        assert(idx + 1 < n);
        ans.push_back(min(a[idx], a[idx + 1]));
        ans.push_back(max(a[idx], a[idx + 1]));
        idx += 2;
    }
    for(int i = 1; i < n; i++){
        if(ans[i] < ans[i - 1]) {
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