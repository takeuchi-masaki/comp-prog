#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    int idx_1 = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            if(idx_1 != -1){
                cout << "NO\n";
                return;
            }
            idx_1 = i;
        }
    }
    if(idx_1 == -1){
        cout << "NO\n";
        return;
    }

    for(int cnt = 1; cnt < n; cnt++){
        int idx = (idx_1 + cnt) % n;
        int idx_prev = (idx - 1 + n) % n;
        if(cnt == 1){
            if(a[idx] != 2){
                cout << "NO\n";
                return;
            }
            continue;
        }

        if(a[idx] > a[idx_prev] + 1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}