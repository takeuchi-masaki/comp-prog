#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

template <typename T>
T modpow(T base, T exp) {
	// base %= MOD;
	T result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    long long ans = 1;
    for(int i = 0; i < n; i++){
        ans += modpow(2ll, (long long)i);
        while(ans < 0) ans += MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}