#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int pow2n = 1<<n;
    vector<int> a(pow2n);
    for(int& i : a) cin >> i;
    sort(a.rbegin(), a.rend());
    int ans = a[0] - a[1] <= k;

    for(int round = 2; round <= n; round++){
        int currIndex = (1<<(round-1));
        for(int check = 0; check < (1<<(round-1)); check++){
            if(a[check] - k <= a[currIndex]){
                // cout << "ok: " << a[check] << ' ' << a[currIndex] << '\n';
                ans++;
                currIndex++;
            }
        }
    }
    cout << ans << '\n';
}