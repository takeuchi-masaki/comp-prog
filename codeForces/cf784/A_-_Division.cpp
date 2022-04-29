#include <bits/stdc++.h>
using namespace std;

void solve() {
	int rating;
	cin >> rating;
	cout << "Division ";
	if (rating <= 1399) {
		cout << "4\n";
	} else if (rating <= 1599) {
		cout << "3\n";
	} else if (rating <= 1899) {
		cout << "2\n";
	} else {
		cout << "1\n";
	}
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