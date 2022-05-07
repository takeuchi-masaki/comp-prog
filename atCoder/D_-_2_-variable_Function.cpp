#include <bits/stdc++.h>
using namespace std;

const long long mx = 1e18;

void solve() {
	long long n;
	cin >> n;
	if (n == 0) {
		cout << "0\n";
		return;
	}
	long long ans = 2 * mx;
	for (long long i = 1; i <= 1e6 + 5; i++) {
		long long l = -1, r = 1e6 + 5;
		while (r - l > 1) {
			long long m = (l + r) >> 1;
			long long sum = i * i * i + i * i * m + i * m * m + m * m * m;
			if (sum >= n) {
				ans = min(ans, sum);
				r = m;
			} else {
				l = m;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}