#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, m;
	cin >> n >> m;
	if (abs(n - m) <= 1) {
		cout << (n + m - 2) << '\n';
		return;
	}
	if (n == 1 || m == 1) {
		cout << "-1\n";
		return;
	}
	long long diff = abs(n - m);
	long long ans = (min(n, m) - 1) * 2;
	if (diff & 1) {
        diff--;
        ans++;
        ans += diff * 2;
	} else {
        ans += diff * 2;
    }
	cout << ans << '\n';
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