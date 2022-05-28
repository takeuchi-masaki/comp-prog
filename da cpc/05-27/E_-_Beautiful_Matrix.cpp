#include <bits/stdc++.h>
using namespace std;

void solve() {
	const int n = 5;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				ans = abs(i - 2) + abs(j - 2);
			}
		}
	}
	assert(ans != -1);
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}