#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	int end = n - 1;
	while (end >= 0 && a[end] == 0) {
		end--;
	}
	bool flip = false;
	for (int i = 0; i <= end; i++) {
		if ((a[i] ^ flip) == 1) {
			cout << "No\n";
			return;
		} else {
			flip ^= 1;
		}
		while (end > i && (a[end] ^ flip) == 0) {
			end--;
		}
	}
	cout << "Yes\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}