#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int day = 1;
	int cycle = 0;
	int mn = 0, mx = 0;
	while (day <= n) {
		if (cycle == 0 || cycle == 1) {
			mx++;
		} else if (cycle == 5 || cycle == 6) {
			mn++;
		}
		cycle = (cycle + 1) % 7;
		day++;
	}
	cout << mn << ' ' << mx << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}