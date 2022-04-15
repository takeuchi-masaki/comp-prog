#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long h;
	cin >> h;
    long long ans = 0, cnt = 0;
	while(h > 0){
        h >>= 1;
        ans += (1LL << cnt);
        cnt++;
    }
    cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.exceptions(cin.failbit);
	solve();
}