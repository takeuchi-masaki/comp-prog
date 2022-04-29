#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < 4 * n - 1; i++) {
		int num;
		cin >> num;
        m[num]++;
	}
    for(auto& [num, cnt]: m){
        if(cnt == 3){
            cout << num << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}