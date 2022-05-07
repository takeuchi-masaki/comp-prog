#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m);
	for (int& i: a) cin >> i;
	for (int& i: b) cin >> i;
	for (int& i: c) cin >> i;

	vector<int> ans(m);

	map<int, vector<int>> need;
	int c_back = -1, c_back2 = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			need[b[i]].push_back(i);
			if (b[i] == c.back()) {
				c_back2 = i;
			}
		}
		if (b[i] == c.back()) {
			c_back = i;
		}
	}

	if (c_back == -1) {
		cout << "NO\n";
		return;
	}
	if (c_back2 != -1) {
		c_back = c_back2;
	}
	ans[m - 1] = c_back;
	if (need.count(c.back())) {
		assert(need[c.back()].back() == c_back);
		need[c.back()].pop_back();
		if (need[c.back()].empty()) {
			need.erase(c.back());
		}
	}
	for (int i = 0; i < m - 1; i++) {
		if (need.count(c[i])) {
			ans[i] = need[c[i]].back();
			need[c[i]].pop_back();
			if (need[c[i]].empty()) {
				need.erase(c[i]);
			}
		} else {
			ans[i] = c_back;
		}
	}
	if (!need.empty()) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i: ans) cout << i + 1 << ' ';
	cout << '\n';
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