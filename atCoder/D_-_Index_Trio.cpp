#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	unordered_map<int, long long> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		m[num]++;
	}
	long long ans = 0;
	if(m.count(1)){
        ans += m[1] * m[1] * m[1];
	    for(auto [num, cnt]: m){
            if(num == 1) {
                continue;
            }
	        ans += cnt * cnt * m[1] * 2;
	    }
	}
	for (auto [num, cnt]: m) {
		for (int i = 2; i * i <= num; i++) {
			if (num % i != 0) {
				continue;
			}
			if (m.count(i) && m.count(num / i)) {
                if(i == num / i){
                    ans += m[i] * m[i] * m[num];
                } else {
                    ans += m[i] * m[num / i] * m[num] * 2;
                }
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}