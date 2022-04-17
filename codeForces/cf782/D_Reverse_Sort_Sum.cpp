#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	// vector<int> ans(n, 9);
	// if (a.back() == n) {
	// 	ans.back() = 1;
	// }
	// else {
	// 	ans.back() = 0;
	// }
    // if(a.front() > 0){
    //     ans.front() = 1;
    // } else {
    //     ans.front() = 0;
    // }
    // for(int i: ans) cout << i << ' ';
    // cout << '\n';
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