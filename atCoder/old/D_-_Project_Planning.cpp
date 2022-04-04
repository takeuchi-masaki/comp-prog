#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k; cin >> n >> k;
    vector<long long> a(n);
    for(long long& i : a) cin >> i;
    long long sum = accumulate(a.begin(), a.end(), 0LL);

    long long l = 0, r = 1e18 / k;
    while(r - l > 1){
        long long m = l + (r - l) / 2;
        long long nec = m * k;
        long long currSum = sum;
        for(auto i : a){
            if(i > m) currSum -= i - m;
        }

        if(currSum >= nec){
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    solve();
}