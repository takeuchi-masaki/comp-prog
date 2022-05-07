#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	long double magnitude = sqrtl(x * x + y * y);
	cout << fixed << setprecision(12);
	cout << x / magnitude << ' ' << y / magnitude << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}