#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    // check all 8 locations
    for(long long i = 1; i <= n; i++){
        long long ans = i * i;
        ans *= ans - 1;
        ans >>= 1;
        ans -= 4 * (i-1)*(i-2);
        cout << ans << '\n';
    }
}