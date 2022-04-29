#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	bool allSame = true, allConsecutive = true;
	vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		a[i] = s[i] - '0';
		if (i > 1 && a[i] != a[i - 1]) {
			allSame = false;
		}
        if (i > 1 && ((a[i - 1] + 1) % 10) != a[i]){
            allConsecutive = false;
        }
	}
    if(allSame || allConsecutive){
        cout << "Weak\n";
    } else {
        cout << "Strong\n";
    }
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}