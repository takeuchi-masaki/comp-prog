#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long a, b;
	cin >> a >> b;
	if (a > 0 && b > 0) {
		cout << "Positive\n";
	} else if (a < 0 && b < 0) {
		if ((b - a) & 1) {
			cout << "Positive\n";
		} else {
			cout << "Negative\n";
		}
	} else {
		cout << "Zero\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}