#include <bits/stdc++.h>
using namespace std;

void solve() {
	string abcd;
	cin >> abcd;
	vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		a[i] = abcd[i] - '0';
	}

	for (int mask = 0; mask < (1 << 3); mask++) {
		int curr = a[0];
		for (int bit = 0; bit < 3; bit++) {
			if (mask >> bit & 1) {
				curr += a[bit + 1];
			} else {
				curr -= a[bit + 1];
			}
		}
		if (curr == 7) {
			for (int bit = 0; bit < 3; bit++) {
				cout << a[bit];
				cout << ((mask >> bit & 1) ? "+" : "-");
			}
			cout << a[3] << "=7\n";
			return;
		}
	}
	exit(1);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}