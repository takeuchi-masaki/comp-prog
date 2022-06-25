#include <bits/stdc++.h>
using namespace std;

void solve() {
	string num1, num2;
	cin >> num1 >> num2;
	int mn = min(num1.size(), num2.size());
	for (int i = 0; i < mn; i++) {
		if (num1[num1.size() - 1 - i] - '0' + num2[num2.size() - 1 - i] - '0' > 9) {
			cout << "Hard\n";
			return;
		}
	}
	cout << "Easy\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}