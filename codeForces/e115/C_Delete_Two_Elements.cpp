#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long sum = accumulate(a.begin(), a.end(), 0);
    long double mean = (long double)sum/n;
    long long target = mean*(n-2);
    // if(sum % n != 0 || target % (n-2) != 0){
    //     cout << 0 << '\n';
    //     return;
    // }
    // cout << 1 << '\n';
    cout << sum << '\n' << mean << '\n' << target << "\n\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}