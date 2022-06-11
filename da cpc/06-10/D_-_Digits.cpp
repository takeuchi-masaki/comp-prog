#include <bits/stdc++.h>
using namespace std;

int digit_sum(int i) {
	int sum = 0;
	while (i > 0) {
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

void solve() {
	int a, x, y;
	cin >> a >> x >> y;
	int ans = 0;
	for (int i = 1; i <= a; i++) {
		int sum = digit_sum(i);
		if ((sum >= x) && (sum <= y)) {
			ans += i;
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}