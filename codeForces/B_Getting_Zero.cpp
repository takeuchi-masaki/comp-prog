#include <bits/stdc++.h>
using namespace std;

const int MOD = 32768;
vector<int> cnt(MOD);

void solve() {
	int n;
	cin >> n;
	n %= MOD;
	cout << cnt[n] << ' ';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.exceptions(cin.failbit);

	for (int i = 1; i < MOD; i++) {
		cnt[i] = MOD - i;
	}
	for (int t = 0; t < 15; t++) {
		for (int i = MOD - 1; i > 0; i--) {
			cnt[i] = min({ cnt[i],
				cnt[(i * 2) % MOD] + 1,
				cnt[(i + 1) % MOD] + 1 });
		}
	}

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}