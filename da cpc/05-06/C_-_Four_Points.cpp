#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
	vector<pair<int, int>> pt(3);
	for (int i = 0; i < 3; i++) {
		cin >> pt[i].first >> pt[i].second;
	}
	sort(pt.begin(), pt.end());

	int minX = INF, minY = INF;
	int maxX = -INF, maxY = -INF;
	for (auto [x, y]: pt) {
		minX = min(minX, x);
		minY = min(minY, y);
		maxX = max(maxX, x);
		maxY = max(maxY, y);
	}

	vector<pair<int, int>> pts = {
		{ minX, minY },
		{ minX, maxY },
		{ maxX, minY }
	};
	for (int i = 0; i < 3; i++) {
		auto [x, y] = pt[i];
		auto [x2, y2] = pts[i];
		if (x != x2 || y != y2) {
			cout << x2 << ' ' << y2 << '\n';
			return;
		}
	}
	cout << maxX << ' ' << maxY << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}