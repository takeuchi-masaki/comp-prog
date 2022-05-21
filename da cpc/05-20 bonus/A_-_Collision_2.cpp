#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int> max_go_left, min_go_right;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			if (max_go_left.count(y[i])) {
				max_go_left[y[i]] = max(max_go_left[y[i]], x[i]);
			} else {
				max_go_left[y[i]] = x[i];
			}
		} else {
			if (min_go_right.count(y[i])) {
				min_go_right[y[i]] = min(min_go_right[y[i]], x[i]);
			} else {
				min_go_right[y[i]] = x[i];
			}
		}
		if (min_go_right.count(y[i]) && max_go_left.count(y[i])) {
			if (min_go_right[y[i]] <= max_go_left[y[i]]) {
				cout << "Yes\n";
				return;
			}
		}
	}
	cout << "No\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}