#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.size();
    bool ok = false;
    string ans = "";
    for(int i = 0; i < n; i++){
        if(s[i]!='a'){
            ans = s.substr(0,(n-i)) + 'a' + s.substr(n-i);
            ok = true;
            break;
        }
    }
    // bool all_a = true;
    // for(int i = 0; i < n; i++){
    //     if(s[i]!='a') {
    //         all_a = false;
    //         break;
    //     }
    // }
    // if(all_a){
    //     ok = false;
    // } else {
    //     for(int i = 0; i < n; i++){
    //         if(s[i]!='a'){
    //             ans = s.substr(0,(n-i)) + 'a' + s.substr(n-i);
    //             ok = true;
    //             break;
    //         }
    //     }
    // }
    cout << (ok?"YES\n":"NO\n");
    if(ok){
        // int start = 0, end = ans.size()-1;
        // bool corr = false;
        // while(start<=end){
        //     if(ans[start]!=ans[end]) {corr = true; break;}
        //     start++, end--;
        // }
        // if(!corr) {
        //     cout << "WRONG ";
        // }
        cout << ans << '\n';
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