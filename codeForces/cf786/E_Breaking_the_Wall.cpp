#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int& i: arr) cin >> i;
	// adj or non-adj
	int min1 = 1e9, min2 = 1e9;
	for (int i: arr) {
		if (i < min1) {
			min2 = min1;
			min1 = i;
		} else if (i < min2) {
			min2 = i;
		}
	}
	long long ans_nonadj = (min1 + 1) / 2 + (min2 + 1) / 2;

    long long min_adj = 1e9;
	for (int i = 0; i < n - 1; i++) {
        int a = min(arr[i], arr[i + 1]);
        int b = max(arr[i], arr[i + 1]);
        long long curr = 0;
        if(b >= a * 2) {
            curr = (b + 1) / 2;
        } else {
            curr = (a + b + 2) / 3;
        }
        min_adj = min(min_adj, curr);
	}

    long long min_three = 1e9;
    for(int i = 0; i < n - 2; i++){
        long long curr = max(arr[i], arr[i + 2]);
        min_three = min(min_three, curr);
    }
    cout << min({ans_nonadj, min_adj, min_three}) << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	solve();
}