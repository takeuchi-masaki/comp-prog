#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int& i: h) cin >> i;
	int ans = h[0];
	for (int i = 1; i < n; i++) {
		if (h[i] <= h[i - 1]) {
			break;
		}
		ans = h[i];
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}