#include <bits/stdc++.h>
using namespace std;

// x * c <= n
// c <= n / x

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;
    long long ans = 0;
    for(long long i = 1; i * i * i <= n; i++){
        for(long long j = i; i * j * j <= n; j++){
            long long k = n / (i * j) - j + 1;
            ans += k;
        }
    }
    cout << ans << '\n';
}