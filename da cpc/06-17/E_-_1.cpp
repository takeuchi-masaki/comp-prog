#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long x;
	cin >> x;
	long long curr = 100;
	int years = 0;
	while (curr < x) {
		// curr *= 1.01L;
		curr += (curr / 100);
		years++;
	}
	cout << years << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}