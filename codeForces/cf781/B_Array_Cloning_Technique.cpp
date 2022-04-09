#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin >> n;
    map<int, int> m, f;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        m[temp]++;
    }

    long long mx_frq = 0;
    for(auto& [num, cnt] : m){
        if(cnt > mx_frq){
            mx_frq = cnt;
        }
    }
    
    long long ans = 0;
    int diff = n - mx_frq;
    while(diff > 0){
        long long next_frq = min(n, mx_frq * 2);
        ans += 1 + (next_frq - mx_frq);
        mx_frq = next_frq;
        diff = n - mx_frq;
    }
    cout << ans << '\n';
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