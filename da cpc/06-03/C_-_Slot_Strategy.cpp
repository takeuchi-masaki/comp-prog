#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<string> slot(n);
	for (auto& s: slot) cin >> s;
	vector<vector<int>> timing(10, vector<int>());
	for (string& s: slot) {
		for (int i = 0; i < (int)s.size(); i++) {
			timing[s[i] - '0'].push_back(i);
		}
	}

	int ans = 1e9;
	for (int i = 0; i < 10; i++) {
		vector<int> cnt(10);
		for (int num: timing[i]) {
			cnt[num]++;
		}
		int mx = -1, mx_num = -1;
		for (int j = 0; j < 10; j++) {
			if (cnt[j] >= mx) {
				mx = cnt[j];
				mx_num = max(mx_num, j);
			}
		}
		int curr = 10 * (mx - 1) + mx_num;
		ans = min(ans, curr);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}