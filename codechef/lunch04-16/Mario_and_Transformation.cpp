#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x;
	cin >> x;
    int state = 0;
    while(x--){
        state++;
        state %= 3;
    }
    switch (state)
    {
    case 0:
        cout << "NORMAL\n";
        break;
    case 1:
        cout << "HUGE\n";
        break;
    case 2:
        cout << "SMALL\n";
        break;
    }
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