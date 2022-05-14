#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long anded, sum;
	cin >> anded >> sum;
	if (anded > sum) {
		cout << "No\n";
		return;
	}
	for (int bit = 0; bit < 64; bit++) {
		if (anded >> bit & 1) {
			sum -= (1LL << (bit + 1));
		}
	}
	if (sum < 0) {
		cout << "No\n";
	} else {
		for (int bit = 0; bit < 64; bit++) {
			if ((sum >> bit & 1) && (anded >> bit & 1)) {
				cout << "No\n";
				return;
			}
		}
		cout << "Yes\n";
	}
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