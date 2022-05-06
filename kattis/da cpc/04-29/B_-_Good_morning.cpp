#include <bits/stdc++.h>
using namespace std;

void solve() {
	int hour1, hour2, minute1, minute2;
	cin >> hour1 >> hour2 >> minute1 >> minute2;
	if (hour1 < hour2) {
		cout << "Takahashi\n";
	} else if (hour2 < hour1) {
		cout << "Aoki\n";
	} else {
		if (minute1 <= minute2) {
			cout << "Takahashi\n";
		} else {
			cout << "Aoki\n";
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}