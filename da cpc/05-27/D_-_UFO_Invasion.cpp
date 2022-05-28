#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	string z = "ZONe";
	int cnt = 0;
	for (int i = 0; i <= (int)(s.size() - z.size()); i++) {
		bool ok = true;
		for (int j = 0; j < (int)z.size(); j++) {
			if (s[i + j] != z[j]) {
				ok = false;
				break;
			}
		}
		cnt += ok;
	}
	cout << cnt << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}