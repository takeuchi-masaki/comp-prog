#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
    int curr = 1, ans = 0;
    while(curr < b){
        curr += (a - 1);
        ans++;
    }
    cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.exceptions(cin.failbit);
	solve();
}