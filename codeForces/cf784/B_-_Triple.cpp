#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		m[num]++;
	}
    for(auto& [num, cnt]: m){
        if(cnt >= 3){
            cout << num << '\n';
            return;
        }
    }
    cout << "-1\n";
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