#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (i == 0 && num != 0) {
			cout << "0\n";
			return;
		}
		m[num]++;
	}
	if (m.begin()->first != 0 || m[0] > 1) {
		cout << "0\n";
		return;
	}
	long long ans = 1;
	for (auto [num, cnt]: m) {
		if (num == 0) {
			continue;
		}
		auto it = m.find(num - 1);
		if (it == m.end()) {
			cout << "0\n";
			return;
		}
		for (int i = 0; i < cnt; i++) {
			ans = (ans * it->second) % MOD;
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}