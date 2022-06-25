#include <bits/stdc++.h>
using namespace std;

void solve() {
	string time;
	int x;
	cin >> time >> x;
	int hr = stoi(time.substr(0, 2));
	int mn = stoi(time.substr(3));
	int add_hr = x / 60;
	int add_mn = x % 60;

	set<string> s;
	int cnt = 0;
	while (true) {
		string curr_hr = to_string(hr);
		string curr_mn = to_string(mn);
		if (curr_hr.size() < 2) {
			curr_hr = "0" + curr_hr;
		}
		if (curr_mn.size() < 2) {
			curr_mn = "0" + curr_mn;
		}
		// cout << curr_hr << ' ' << curr_mn << '\n';
		reverse(curr_hr.begin(), curr_hr.end());
		if (curr_hr == curr_mn) {
			s.insert(curr_hr);
		}

		mn += add_mn;
		while (mn >= 60) {
			mn -= 60;
			hr++;
		}
		hr += add_hr;
		while (hr >= 24) {
			hr -= 24;
		}

		if (++cnt > 1e4) break;
	}
	cout << s.size() << '\n';
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