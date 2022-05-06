#include <bits/stdc++.h>
using namespace std;

void solve() {
	int v;
	vector<int> use(3);
	cin >> v;
	for (int& i: use) cin >> i;
	// f -> m -> t
	int curr = 0;
	while (true) {
		if (v - use[curr] < 0) {
			switch (curr) {
				case 0:
					cout << "F\n";
					break;
				case 1:
					cout << "M\n";
					break;
				case 2:
					cout << "T\n";
					break;
			}
			return;
		}
		v -= use[curr];
		curr = (curr + 1) % 3;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}