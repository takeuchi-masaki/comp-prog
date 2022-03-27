#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long a, b; cin >> a >> b;
    assert(a < 1e8 && b < 1e8);

    int ans = 0;
    for(int i = a; i <= b; i++){
        string s = to_string(i);
        long long mult = 1;
        long long sum = 0;
        for(char c : s){
            sum += c - '0';
            mult *= c - '0';
        }
        if(mult % sum == 0) ans++;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}