#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	vector<long long> pref(n);
	pref[0] = a[0];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}

	vector<long long> max_pref(n);
	max_pref[0] = pref[0];
	for (int i = 1; i < n; i++) {
		if (pref[i] > max_pref[i - 1]) {
			max_pref[i] = pref[i];
		} else {
			max_pref[i] = max_pref[i - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		auto it = lower_bound(max_pref.begin(), max_pref.end(), x);
		if (it == max_pref.end()) {
			if (pref.back() <= 0) {
				cout << "-1 ";
				continue;
			}
			long long minus_mx = x - max_pref.back();
			long long cycles = (minus_mx + pref.back() - 1) / pref.back();
			long long ans = cycles * n;
			x -= cycles * pref.back();
			auto it2 = lower_bound(max_pref.begin(), max_pref.end(), x);
			ans += it2 - max_pref.begin();
			cout << ans << ' ';
		} else {
			cout << it - max_pref.begin() << ' ';
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}