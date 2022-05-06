#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long modpow(long long base, long long exp) {
	base %= MOD;
	long long result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), d(n);
	for (int& i: a) cin >> i;
	for (int& i: b) cin >> i;
	for (int& i: d) cin >> i;

	vector<bool> one_option(n);
	map<int, int> a_map, b_map;
	for (int i = 0; i < n; i++) {
		a_map[a[i]] = i;
		b_map[b[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			one_option[i] = true;
			continue;
		}
		if (one_option[i] || d[i] == 0) {
			continue;
		}

		one_option[i] = true;
		queue<pair<int, bool>> check;
		if (a[i] == d[i]) {
			check.push({ d[i], true });
		} else {
			check.push({ d[i], false });
		}
		while (!check.empty()) {
			auto [curr, is_a] = check.front();
			check.pop();
			if ((is_a && one_option[b_map[curr]]) || (!is_a && one_option[a_map[curr]])) {
				continue;
			}

			if (is_a) {
				one_option[b_map[curr]] = true;
				check.push({ a[b_map[curr]], true });
				// d[b_map[curr]] = a[b_map[curr]];
			} else {
				one_option[a_map[curr]] = true;
				check.push({ b[a_map[curr]], false });
				// d[a_map[curr]] = b[a_map[curr]];
			}
		}
	}

	// for(bool b: one_option){
	//     cout << b << ' ';
	// }
	// cout << '\n';

	long long ans = 1;
	for (int i = 0; i < n; i++) {
		if (one_option[i]) {
			continue;
		}
		ans <<= 1;
		ans %= MOD;
		one_option[i] = true;
		queue<pair<int, bool>> check;
		check.push({ a[i], true });
		check.push({ b[i], true });
		while (!check.empty()) {
			auto [curr, is_a] = check.front();
			check.pop();
			if ((is_a && one_option[b_map[curr]]) || (!is_a && one_option[a_map[curr]])) {
				continue;
			}

			if (is_a) {
				one_option[b_map[curr]] = true;
				check.push({ a[b_map[curr]], true });
				// d[b_map[curr]] = a[b_map[curr]];
			} else {
				one_option[a_map[curr]] = true;
				check.push({ b[a_map[curr]], false });
				// d[a_map[curr]] = b[a_map[curr]];
			}
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