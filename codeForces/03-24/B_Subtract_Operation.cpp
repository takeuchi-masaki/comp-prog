#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;  cin >> n >> k;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end());
    if(k == 0){
        for(int i = 0; i < n-1; i++){
            if(a[i] == a[i + 1]) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
        return;
    }

    for(int i : a){
        auto it = lower_bound(a.begin(), a.end(), i + k);
        if(it != a.end() && *it == i + k){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}