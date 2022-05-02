#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;
    bool haveA = false;
    for(char c: t) {
        if(c == 'a') {
            haveA = true;
            break;
        }
    }
    if(haveA && t.size() >= 2){
        cout << "-1\n";
        return;
    }
    if(t.size() == 1 && t[0] == 'a'){
        cout << "1\n";
        return;
    }
    cout << (1LL << s.size()) << '\n';
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