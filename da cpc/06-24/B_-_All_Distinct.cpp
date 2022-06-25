#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		m[num]++;
	}
	int extra = 0;
	for (auto [num, cnt]: m) {
		extra += cnt - 1;
	}
	int ans = extra;
	if (ans & 1) ans++;
	cout << n - ans << '\n';
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