#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	long double ans = (long double)a / 100 * b;
	cout << setprecision(12) << fixed;
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}