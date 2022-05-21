#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<string> vs(n);
	for (auto& s: vs) cin >> s;

	// horizontal
	for (int r = 0; r < n; r++) {
		int cnt = 0;
		for (int i = 0; i < 6; i++) {
			cnt += (vs[r][i] == '#');
		}
		if (cnt >= 4) {
			cout << "Yes\n";
			return;
		}
		for (int c = 6; c < n; c++) {
			cnt += (vs[r][c] == '#') - (vs[r][c - 6] == '#');
			if (cnt >= 4) {
				cout << "Yes\n";
				return;
			}
		}
	}

	// vertical
	for (int c = 0; c < n; c++) {
		int cnt = 0;
		for (int i = 0; i < 6; i++) {
			cnt += (vs[i][c] == '#');
		}
		if (cnt >= 4) {
			cout << "Yes\n";
			return;
		}
		for (int r = 6; r < n; r++) {
			cnt += (vs[r][c] == '#') - (vs[r - 6][c] == '#');
			if (cnt >= 4) {
				cout << "Yes\n";
				return;
			}
		}
	}

	// diag1
	for (int addr = 0; addr <= (n - 6); addr++) {
		for (int c = 0; c <= (n - 6); c++) {
			int cnt = 0;
			for (int i = 0; i < 6; i++) {
				cnt += (vs[i + addr][i + c] == '#');
			}
			if (cnt >= 4) {
				cout << "Yes\n";
				return;
			}
		}
	}

	// diag2
	for (int addr = 0; addr <= (n - 6); addr++) {
		for (int c = n - 1; c >= 5; c--) {
			int cnt = 0;
			for (int i = 0; i < 6; i++) {
				cnt += (vs[i + addr][c - i] == '#');
			}
			if (cnt >= 4) {
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