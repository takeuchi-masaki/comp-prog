#include <bits/stdc++.h>
using namespace std;

void solve() {
	int noodleCnt, days;
	cin >> noodleCnt >> days;
	vector<int> plan(days);
	map<int, int> cntNoodleLen;
	for (int i = 0; i < noodleCnt; i++) {
		int len;
		cin >> len;
		cntNoodleLen[len]++;
	}
	for (int& i: plan) cin >> i;
	if (!cntNoodleLen.count(plan[0])) {
		cout << "No\n";
		return;
	}

	for (int i = 1; i < days; i++) {
		if (!cntNoodleLen.count(plan[i])) {
			cout << "No\n";
			return;
		}
		if (plan[i] == plan[i - 1] && cntNoodleLen[plan[i]] < 2) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}