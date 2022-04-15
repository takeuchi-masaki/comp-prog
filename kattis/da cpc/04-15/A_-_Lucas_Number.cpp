#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
    vector<long long> lucas(n + 1);
    lucas[0] = 2, lucas[1] = 1;
    for(int i = 2; i <= n; i++){
        lucas[i] = lucas[i - 1] + lucas[i - 2];
    }
    cout << lucas[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.exceptions(cin.failbit);
	solve();
}