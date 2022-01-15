#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    string s; 
    cin >> n >> k >> s;
    vector<int> a(26);
    for(char c : s){
        a[c - 'a']++;
    }
    
    int pairs = 0, odd = 0;
    for(int cnt : a){
        if(cnt&1){
            odd++;
            cnt--;
        }
        if(cnt == 0) continue;
        pairs += cnt>>1;
    }

    int ans = 2*(pairs / k);
    int rem = 2*(pairs % k) + odd;
    if(rem >= k) ans++;

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}