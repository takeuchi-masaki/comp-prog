#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, k; cin >> n >> k;
    vector<long long> a(n), prefix(n + 1);
    for(long long & i : a) cin >> i;
    for(long long i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + a[i];
    }
    long long ans = 0;
    for(long long i = 1; i < n + 1; i++){
        // prefix[i] - prefix[j] > k
        if(prefix[i] - k < 0) continue;
        ans += upper_bound(prefix.begin(), prefix.end(), prefix[i] - k) - prefix.begin();
    }
    cout << ans << '\n';
}