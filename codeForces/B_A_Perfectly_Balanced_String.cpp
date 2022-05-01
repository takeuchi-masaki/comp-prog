#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	set<char> S;
	for (char c: s) {
		S.insert(c);
	}

	int n = s.size();
    vector<int> prev(26, -1);
    for(int i = 0; i < n; i++){
        int curr = s[i] - 'a';
        if(prev[curr] != -1 && i - prev[curr] < S.size()) {
            cout << "NO\n";
            return;
        }
        prev[curr] = i;
    }
	cout << "YES\n";
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