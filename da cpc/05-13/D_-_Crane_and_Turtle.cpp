#include <bits/stdc++.h>
using namespace std;

void solve() {
	int animals, legs;
	cin >> animals >> legs;
	if ((legs & 1) || legs > animals * 4 || animals * 2 > legs) {
		cout << "No\n";
		return;
	}
	while (animals * 2 != legs) {
		if (legs < 4) {
			break;
		}
		legs -= 4;
		animals--;
	}
	if (animals * 2 == legs) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}