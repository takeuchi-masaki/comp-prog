#include <bits/stdc++.h>
using namespace std;

long long POW(long long base, long long exp) {
	long long result = 1;
	while (exp > 0) {
		if (exp & 1) result *= base;
		base *= base;
		exp >>= 1;
	}
	return result;
}

void solve() {
	long long n, k;
	cin >> n >> k;

	long long mult = n / k;
	long long ans = POW(mult, 3);
	if (k & 1) {
		cout << ans << '\n';
		return;
	}

	mult = (n + (k / 2)) / k;
	ans += POW(mult, 3);
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}