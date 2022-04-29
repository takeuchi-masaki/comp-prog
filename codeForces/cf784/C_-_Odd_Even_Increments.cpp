#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	bool parityEven = a[0] & 1, parityOdd = a[1] & 1;
	for (int i = 2; i < n; i++) {
		if (i & 1) {
			if ((a[i] & 1) != parityOdd) {
				cout << "NO\n";
				return;
			}
		} else {
			if ((a[i] & 1) != parityEven) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}