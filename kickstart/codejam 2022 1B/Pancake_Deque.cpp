#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		dq.push_back(num);
	}
    int ans = 0, currMax = -1;
    while(!dq.empty()){
        int curr;
        if(dq.front() <= dq.back()){
            curr = dq.front();
            dq.pop_front();
        } else {
            curr = dq.back();
            dq.pop_back();
        }
        if(curr >= currMax){
            currMax = curr;
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}