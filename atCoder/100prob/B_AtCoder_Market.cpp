#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    long long ans = 1e18;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long entrance = a[i], exit = b[j];
            long long curr = 0;
            for(int cus = 0; cus < n; cus++){
                long long diff = abs(a[cus] - b[cus]);
                long long aFirst = abs(a[cus] - entrance) + abs(b[cus] - exit);
                long long bFirst = abs(b[cus] - entrance) + abs(a[cus] - exit);
                curr += diff + min(aFirst, bFirst);
            }
            ans = min(ans, curr);
        }
    }
    cout << ans << '\n';
}