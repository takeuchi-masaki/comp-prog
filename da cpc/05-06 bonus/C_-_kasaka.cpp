#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.size();

	int cnt_a_front = 0, cnt_a_back = 0;
	while (cnt_a_front < n && s[cnt_a_front] == 'a') {
		cnt_a_front++;
	}
	while (cnt_a_back < n && s[n - 1 - cnt_a_back] == 'a') {
		cnt_a_back++;
	}
	int addA = cnt_a_back - cnt_a_front;
	if (addA < 0) {
		cout << "No\n";
		return;
	}

	string t {};
	for (int i = 0; i < addA; i++) {
		t.push_back('a');
	}
	t += s;

	n = (int)t.size();
	for (int i = 0; i < n / 2; i++) {
		if (t[i] != t[n - 1 - i]) {
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