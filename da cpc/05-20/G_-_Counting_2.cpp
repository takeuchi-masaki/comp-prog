#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	sort(a.begin(), a.end());
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		auto it = lower_bound(a.begin(), a.end(), x);
		cout << (a.end() - it) << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}