#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	vector<int> need(31);
	for (int i: a) {
		for (int bit = 0; bit <= 30; bit++) {
			if (i >> bit & 1) {
				continue;
			} else {
				need[bit]++;
			}
		}
	}
	int ans = 0;
	for (int bit = 30; bit >= 0; bit--) {
		if (need[bit] <= k) {
			ans += (1 << bit);
			k -= need[bit];
		}
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