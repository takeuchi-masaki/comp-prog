#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<pair<long long, long long>> p(2);
	for (int i = 0; i < 2; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(), p.end());
	vector<pair<long long, long long>> pts = {
		{ -2, -1 },
		{ -2, 1 },
		{ -1, -2 },
		{ -1, 2 },
		{ 1, -2 },
		{ 1, 2 },
		{ 2, -1 },
		{ 2, 1 }
	};
	auto [x, y] = p[0];
	auto [x2, y2] = p[1];
	for (auto [a, b]: pts) {
		pair<long long, long long> c = {
			x2 + (a - x),
			y2 + (b - y)
		};
		for (auto p: pts) {
			if (c == p) {
				cout << "Yes\n";
				return;
			}
		}
	}
	cout << "No\n";
}



int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}