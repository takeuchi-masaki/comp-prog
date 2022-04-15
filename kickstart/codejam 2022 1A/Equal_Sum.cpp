#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	long long total = 0;
	for (int i = 0; i < 30; i++) {
		cout << (1 << i) << ' ';
		total += (1 << i);
	}
	
	vector<int> values;
	for (int i = 1; i <= 70; i++) {
		int val = (1 << 29) + i;
		cout << val << ' ';
		total += val;
		values.push_back(val);
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		total += num;
		values.push_back(num);
	}
	total >>= 1;

    sort(values.rbegin(), values.rend());
	vector<int> ans;
	for (int i: values) {
		if (total - i >= 0) {
			total -= i;
			ans.push_back(i);
		}
	}

	for (int i = 0; i < 30; i++) {
		if (total >> i & 1) {
			ans.push_back(1 << i);
		}
	}
	for (int i: ans) cout << i << ' ';
	cout << endl;
}

int main() {
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}