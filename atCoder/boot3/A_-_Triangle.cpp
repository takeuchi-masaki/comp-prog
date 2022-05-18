#include <bits/stdc++.h>
using namespace std;

/*
	area of a triangle with 3 points (x, y) given that 1 point is (0, 0)
	1e9 y3 = s + x3
*/

void solve() {
	long long s;
	cin >> s;
	long long mx = 1e9;
	vector<long long> x = { 0, mx };
	vector<long long> y = { 0, 1 };
	y.push_back((s + mx - 1) / mx);
	x.push_back(y.back() * mx - s);
	// x.push_back((mx - (s % mx)) % mx);
	// y.push_back((s + x.back()) / mx);

	// cout << abs(x[1] * y[2] - y[1] * x[2]) << '\n';
	assert(abs(x[1] * y[2] - y[1] * x[2]) == s);
	for (int i = 0; i < 3; i++) {
		cout << x[i] << ' ' << y[i] << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}