#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> s >> k;
	vector<bool> special(26);
	for (int i = 0; i < k; i++) {
		char sp;
		cin >> sp;
		special[sp - 'a'] = true;
	}

    int ans = 0;
	vector<int> prefix_special;
	for (int i = 1; i < n; i++) {
        if (special[s[i] - 'a']) {
            if(prefix_special.empty()) {
                ans = i;
            } else {
                ans = max(ans, i - prefix_special.back());
            }
            prefix_special.push_back(i);
        }
    }
    cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
}