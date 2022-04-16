#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x;
	cin >> x;
	if (x & 1) {
		cout << "-1\n";
		return;
	}
	for (int i = 0; i < 30; i++) {
		if ((1 << i) == x) {
			cout << "-1\n";
			return;
		}
	}
    
	int halfX = x / 2;
	for (int i = 0; i < 30; i++) {
		int a = (1 << i);
		int b = halfX - a;
        if(a + b + (a^b) == x){
            cout << 0 << ' ' << a << ' ' << b << '\n';
            return;
        }
	}
    exit(1);
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