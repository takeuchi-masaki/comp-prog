#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i: a) cin >> i;

    long long ans = 1e18;
	for (int zero = 0; zero < n; zero++) {
        long long curr = 0;
        long long prev = 0;
        for(int i = zero - 1; i >= 0; i--){
            if(a[i] > prev){
                curr++;
                prev = a[i];
            } else {
                long long next_cnt = (prev / a[i]) + 1;
                curr += next_cnt;
                prev = next_cnt * a[i];
            }
        }
        prev = 0;
        for(int i = zero + 1; i < n; i++){
            if(a[i] > prev){
                curr++;
                prev = a[i];
            } else {
                long long next_cnt = (prev / a[i]) + 1;
                curr += next_cnt;
                prev = next_cnt * a[i];
            }
        }
        // cout << zero << ' ' << curr << '\n';
        ans = min(ans, curr);
	}
    cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}