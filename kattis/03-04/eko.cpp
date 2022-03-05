#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n, m; cin >> n >> m;
    vector<long long> h(n);
    for(long long& l : h) cin >> l;

    // binary search for optimal cutting height
    long long l = 0, r = 1e9;
    while(r - l > 1){
        long long mid = l + (r - l)/2;
        long long curr = 0;
        for(long long i : h){
            curr += max(0LL, i - mid);
            if(curr >= m) break;
        }
        if(curr >= m){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}