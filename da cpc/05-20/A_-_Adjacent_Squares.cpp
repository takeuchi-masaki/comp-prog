#include <bits/stdc++.h>
using namespace std;

void solve() {
	int h, w, r, c;
	cin >> h >> w >> r >> c;
	r--, c--;
	vector<pair<int, int>> directions = {
		{ r - 1, c },
		{ r + 1, c },
		{ r, c - 1 },
		{ r, c + 1 }
	};
	int ans = 0;
	for (auto [x, y]: directions) {
		if (x < 0 || y < 0 || x >= h || y >= w) continue;
		ans++;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}