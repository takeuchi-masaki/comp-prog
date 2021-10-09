#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
template <typename T>
T modpow(T base, T exp) {
	base %= MOD;
	T result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

void solve(){
    long long n, k; cin >> n >> k;
    string s = "";
    while(k > 0){
        if(k&1) s.push_back('1');
        else s.push_back('0');
        k>>=1;
    }
    reverse(s.begin(), s.end());
    // cout << s << endl;
    
    long long ans = 0, pow = 0;
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '1') ans = (ans + modpow(n, pow)) % MOD;
        pow++;
    }

    cout << ans << endl;
    // cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}