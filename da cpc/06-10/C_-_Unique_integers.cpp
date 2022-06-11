#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	sort(a.begin(), a.end());

	int unique = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			unique++;
		}
	}
	cout << unique << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}