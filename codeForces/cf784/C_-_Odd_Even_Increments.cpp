#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;
	bool sameParity1 = true, sameParity2 = true;

	for (int i = 2; i < n; i += 2) {
		sameParity1 = ((a[i] & 1) == (a[i - 2] & 1));
        if(!sameParity1) {
            break;
        }
	}
    for(int i = 3; i < n; i += 2){
        sameParity2 = ((a[i] & 1) == (a[i - 2] & 1));
        if(!sameParity2) {
            break;
        }
    }
    if(sameParity1 && sameParity2){
        cout << "YES\n";
    } else {
        cout << "NO\n";
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