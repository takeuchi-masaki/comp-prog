#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> sticks(n);
    for(int & i : sticks) cin >> i;
    sort(sticks.begin(), sticks.end());
    int median = sticks[n/2];
    long long ans = 0;
    for(int i : sticks) ans += abs(i - median);
    cout << ans << '\n';
}