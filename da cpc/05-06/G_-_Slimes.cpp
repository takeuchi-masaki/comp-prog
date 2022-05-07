#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long init, mult, need;
	cin >> init >> need >> mult;
	int ans = 0;
	while (init < need) {
		init *= mult;
		ans++;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}