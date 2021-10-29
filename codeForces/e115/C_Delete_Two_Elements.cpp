#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

void solve(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    long long need = 2*sum/n;
    if( 2*sum%n != 0 ){
        cout << 0 << '\n';
        return;
    }
    unordered_map<long long, int, custom_hash> m;
    for(long long i:a){
        m[i]++;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long twosum = need-a[i];
        if(m.count(twosum)){
            ans += m[twosum];
            if(twosum == a[i]) ans--;
        }
    }
    cout << ans/2 << '\n';
    // cout << sum << '\n' << need << "\n\n";
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