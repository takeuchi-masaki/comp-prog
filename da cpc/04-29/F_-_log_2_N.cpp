#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n;
	cin >> n;
	long long curr = 1, k = 0;
	while (curr <= n) {
		curr <<= 1;
		k++;
	}
	cout << k - 1 << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}