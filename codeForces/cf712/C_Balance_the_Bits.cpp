#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string res1 = "", res2 = "";
    bool ok = true;
    int one = 0, zero = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='1'){
            one++;
        } else {
            zero++;
        }
    }
    if(zero&1){
        ok = false;
    } else if(s[0]=='0' || s[n-1]=='0') {
        ok = false;
    } else {
        int k = one;
        int cnt = 0;
        bool open = true;
        for(int i = 0; i < n; i++){
            if(s[i]=='1'){
                if(cnt<k/2) {
                    res1.push_back('(');
                    res2.push_back('(');
                } else {
                    res1.push_back(')');
                    res2.push_back(')');
                }
                cnt++;
            } else {
                if(open){
                    res1.push_back('(');
                    res2.push_back(')');
                } else {
                    res1.push_back(')');
                    res2.push_back('(');
                }
                open = !open;
            }
        }
    }
    cout << (ok?"YES\n":"NO\n");
    if(ok){
        cout << res1 << '\n' << res2 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("input.txt","r",stdin);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}