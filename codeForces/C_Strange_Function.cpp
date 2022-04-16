#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	long long n;
	cin >> n;
	long long ans = (n << 1) % MOD;
	long long mult = 2, curr = 2;
	while (mult <= n) {
		ans = (ans + n / mult) % MOD;
        curr++;
		mult = lcm(mult, curr);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}