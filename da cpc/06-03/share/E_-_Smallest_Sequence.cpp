#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;

	int ans = a.back();
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			ans = a[i];
			break;
		}
	}

	for (int& i: a) {
		if (i == ans) {
			continue;
		}
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}