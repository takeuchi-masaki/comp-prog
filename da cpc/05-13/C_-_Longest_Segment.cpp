#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> pts(n);
	for (auto& [x, y]: pts) cin >> x >> y;
	long double ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto [x1, y1] = pts[i];
			auto [x2, y2] = pts[j];
			ans = max(ans, sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
		}
	}
	cout << fixed << setprecision(12);
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}