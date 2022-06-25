#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(10);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		num %= 10;
		a[num]++;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if ((i + j + k) % 10 == 3) {
					bool bad = false;
					if (--a[i] < 0) bad = true;
					if (--a[j] < 0) bad = true;
					if (--a[k] < 0) bad = true;
					if (bad) {
						a[i]++;
						a[j]++;
						a[k]++;
					} else {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
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