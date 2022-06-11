#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	string s;
	cin >> s;

	map<int, int> mn_right, mx_left;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') {
			auto it = mx_left.find(y[i]);
			if ((it != mx_left.end()) && (it->second > x[i])) {
				cout << "Yes\n";
				return;
			}
			if (mn_right.count(y[i])) {
				mn_right[y[i]] = min(mn_right[y[i]], x[i]);
			} else {
				mn_right.insert({ y[i], x[i] });
			}
		} else {
			auto it = mn_right.find(y[i]);
			if ((it != mn_right.end()) && (it->second < x[i])) {
				cout << "Yes\n";
				return;
			}
			if (mx_left.count(y[i])) {
				mx_left[y[i]] = max(mx_left[y[i]], x[i]);
			} else {
				mx_left.insert({ y[i], x[i] });
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