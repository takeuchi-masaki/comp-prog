#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	vector<int> ans;
	long long curr = 4;
	ans.push_back(0);
	ans.push_back(2);
	ans.push_back(6);
	while (ans.back() + curr <= 1e9) {
		ans.push_back(ans.back() + curr);
		curr += 2;
		ans.push_back(ans.back() + curr);
		curr += 2;
		ans.push_back(ans.back() + curr);
	}

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
		auto it = lower_bound(ans.begin(), ans.end(), n);
		cout << it - ans.begin() + 1 << '\n';
	}
}