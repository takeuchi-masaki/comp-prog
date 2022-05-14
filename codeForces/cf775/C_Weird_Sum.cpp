#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> color(n, vector<int>(m));
	for (auto& vi: color) {
		for (int& i: vi) {
			cin >> i;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}