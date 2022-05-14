#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string prev = "1";
	for (int i = 2; i <= n; i++) {
		string curr = prev;
		curr.push_back(' ');
		curr += to_string(i);
		curr.push_back(' ');
		curr += prev;
		prev = move(curr);
	}
	cout << prev << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}