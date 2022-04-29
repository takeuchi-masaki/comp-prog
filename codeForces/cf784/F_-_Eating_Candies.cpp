#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> w(n);
	for (int& i: w) cin >> i;
	vector<long long> pref(n), pref2(n);
	pref[0] = w[0], pref2[0] = w[n - 1];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + w[i];
	}
	for (int i = 1; i < n; i++) {
		pref2[i] = pref2[i - 1] + w[n - 1 - i];
	}

	// for(int i: pref) cout << i << ' ';
	// cout << '\n';
	// for(int i: pref2) cout << i << ' ';
	// cout << '\n';
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int remain = n - 1 - i;
		int l = -1, r = remain - 1;
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			if (pref2[m] >= pref[i]) {
				r = m;
			} else {
				l = m;
			}
		}
		if (pref2[r] == pref[i]) {
			ans = max(ans, (r + i + 2));
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