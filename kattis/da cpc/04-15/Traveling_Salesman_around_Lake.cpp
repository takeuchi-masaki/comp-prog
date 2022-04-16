#include <bits/stdc++.h>
using namespace std;

void solve() {
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	int currMax = a[0] + k - a[n - 1];
	for (int i = 1; i < n; i++) {
		currMax = max(currMax, a[i] - a[i - 1]);
	}
	cout << k - currMax << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.exceptions(cin.failbit);
	solve();
}