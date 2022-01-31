#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;
    for(int& i : c) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long ans = 0;
    for(int i : b){
        int cntHigh = lower_bound(a.begin(), a.end(), i) - a.begin();
        int cntLow = c.end() - upper_bound(c.begin(), c.end(), i);
        ans += (long long)cntHigh * cntLow;
    }
    cout << ans << '\n';
}