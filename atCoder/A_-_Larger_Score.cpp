#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (auto& i: a) cin >> i;
	long long s = 0;
	for (int i = 0; i < k; i++) {
		s += a[i];
	}
	vector<pair<long long, int>> numIdx;
	for (int i = k; i < n; i++) {
		numIdx.push_back({ a[i], i });
	}
	sort(numIdx.begin(), numIdx.end());
	vector<int> min_idx(numIdx.size());
	min_idx.back() = numIdx.back().second;
	for (int i = (int)numIdx.size() - 2; i >= 0; i--) {
		min_idx[i] = min(min_idx[i + 1], numIdx[i].second);
	}

	bool ok = false;
	int ans = 1e9;
	for (int i = 0; i < k; i++) {
		int l = -1, r = numIdx.size() - 1;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (numIdx[m].first > a[i]) {
				r = m;
			} else {
				l = m;
			}
		}
		if (numIdx[r].first > a[i]) {
			ok = true;
			// cout << a[i] << ' ' << numIdx[r].first << ' ' << numIdx[r].second << ' ' << min_idx[r] << '\n';
			ans = min(ans, min_idx[r] - i);
		}
	}
	if (ok) {
		cout << ans << '\n';
	} else {
		cout << "-1\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}