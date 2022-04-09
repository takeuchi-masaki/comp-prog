#include <bits/stdc++.h>
using namespace std;

const int MOD = 32768;
vector<int> cnt(MOD);

void solve(){
    int n; cin >> n;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);

    for(int i = MOD - 15; i < MOD; i++){
        cnt[i] = MOD - i;
        // cout << cnt[i] << '\n';
    }
    int curr = 1;
    for(int i = (MOD>>1); i > 0; i>>=1){
        cnt[i] = curr;
        curr++;
    }
    for(int i = 1; i < MOD; i++){
        cout << cnt[i] << '\n';
    }

    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}