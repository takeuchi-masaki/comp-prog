#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        m[a]++;
    }
    
    if(n&1){
        if(!m.count(0) || m[0] != 1){
            cout << "0\n";
            return;
        }
        for(int i = 2; i < n; i += 2){
            if(!m.count(i) || m[i] != 2){
                cout << "0\n";
                return;
            }
        }
    } else {
        for(int i = 1; i < n; i += 2){
            if(!m.count(i) || m[i] != 2){
                cout << "0\n";
                return;
            }
        }
    }
    
    long long ans = 1;
    for(int i = 0; i < n/2; i++){
        ans <<= 1;
        if(ans >= MOD){
            ans %= MOD;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}