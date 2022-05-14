#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	int n;
	cin >> s >> n;
	vector<string> names(n);
	vector<int> rank(26);
	assert((int)s.size() == 26);
	for (int i = 0; i < 26; i++) {
		rank[s[i] - 'a'] = i;
	}
	for (string& name: names) cin >> name;
	sort(names.begin(), names.end(),
		[&](string& s1, string& s2) {
			for (int i = 0; i < (int)min(s1.size(), s2.size()); i++) {
				if (s1[i] == s2[i]) {
					continue;
				}
				return rank[s1[i] - 'a'] < rank[s2[i] - 'a'];
			}
			return s1.size() < s2.size();
		});
	for (string name: names) {
		cout << name << '\n';
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}