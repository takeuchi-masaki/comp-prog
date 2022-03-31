#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long l, r, a;
    cin >> l >> r >> a;
    long long ans = r/a + r%a;

    long long r2 = r/a - 1;
    r2 *= a;
    r2 = r2 + a - 1;
    
    if(r/a > 0 && l <= r2){
        long long ans2 = r2/a + r2%a;
        ans = max(ans, ans2);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}