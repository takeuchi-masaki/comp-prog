#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, d, c, m;
    cin >> n >> d >> c >> m;
    string s; cin >> s;
    long long dogCount = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'D') dogCount++;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'D') {
            d--; c+=m;
            if(d<0) break;
            dogCount--;
        } else {
            c--;
            if(c<0) break;
        }
    }
    if(dogCount) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}