#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long a, b;
	cin >> a >> b;
	while (a > 0 && b > 0) {
		int curr = (a % 10) + (b % 10);
		if (curr > 9) {
			cout << "Hard\n";
			return;
		}
		a /= 10;
		b /= 10;
	}
	cout << "Easy\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}