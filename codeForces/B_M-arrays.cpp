#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& i: a) cin >> i;

	vector<int> mp(m);
	for (int i: a) mp[i % m]++;
	int ans = (mp[0] > 0);
	for (int i = 1; i < (m + 1) / 2; i++) {
		int a = max(mp[i], mp[m - i]), b = min(mp[i], mp[m - i]);
		if (a == 0) {
			continue;
		} else if (a <= b + 1) {
			ans++;
		} else if (b == 0) {
			ans += a;
		} else {
			if (a >= b * 2) {
				ans += b;
				a -= b * 2;
				ans += a;
			} else {
				int l = 0, r = a;
				while (r - l > 1) {
					int m = l + (r - l) / 2;
					int a2 = a - m * 2, b2 = b - m;
					if (a2 - b2 < 1) {
						r = m;
					} else {
						l = m;
					}
				}
				ans += r;
			}
		}
	}
	if (m % 2 == 0) ans += (mp[m / 2] > 0);
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