#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int& i: x) cin >> i;

	// number : prv index, prv cnt, start
	map<int, tuple<int, int, int>> m;
	int mx = 1, ans_start = 0, ans_end = 0, ans_val = x.front();
	for (int i = 0; i < n; i++) {
		auto it = m.find(x[i]);
		if (it != m.end()) {
			auto& [prev_idx, prev_cnt, start] = it->second;
			int separation = i - prev_idx - 1;
			if (separation >= prev_cnt) {
				prev_idx = i;
				prev_cnt = 1;
				start = i;
			} else {
				prev_idx = i;
				prev_cnt = prev_cnt - separation + 1;
				if (prev_cnt > mx) {
					mx = prev_cnt;
					ans_start = start;
					ans_end = i;
					ans_val = x[i];
				}
			}
		} else {
			m[x[i]] = { i, 1, i };
		}
	}
	cout << ans_val << ' ' << ans_start + 1 << ' ' << ans_end + 1 << '\n';
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