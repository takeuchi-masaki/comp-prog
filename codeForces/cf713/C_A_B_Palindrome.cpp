#include <bits/stdc++.h>
using namespace std;

void bad(){
    cout << "-1\n";
}

void solve(){
    int cnt[2]; cin >> cnt[0] >> cnt[1];
    string s; cin >> s;
    int n = cnt[0]+cnt[1];
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(s[i]=='?') continue;
        cnt[s[i]-'0']--;
    }
    // cout << cnt[0] << ' ' << cnt[1] << '\n';
    for(int i = 0; i < n/2; i++){
        int comp = n-1-i;
        if(s[i]==s[comp]) continue;
        if(s[i]=='?'){
            s[i]=s[comp];
            cnt[s[i]-'0']--;
        } else if(s[comp]=='?'){
            s[comp]=s[i];
            cnt[s[i]-'0']--;
        } else {
            // cout << "mismatch ";
            bad();
            return;
        }
    }
    // cout << cnt[0] << ' ' << cnt[1] << '\n';
    if(cnt[0]<0 || cnt[1]<0) {
        bad();
        return;
    }
    if(cnt[0]&1 && cnt[1]&1){
        bad();
        return;
    }
    int q_mark = cnt[0]+cnt[1];
    bool odd = (n&1)==1;
    if(q_mark&1){
        if(!odd || s[n/2]!='?') {
            bad();
            return;
        }
        if(cnt[0]&1){
            s[n/2]='0';
            cnt[0]--;
        } else {
            s[n/2]='1';
            cnt[1]--;
        }
    } else {
        if(odd && s[n/2]=='?'){
            bad();
            return;
        }
    }
    for(int i = 0; i < n/2; i++){
        if(s[i]!='?') continue;
        int comp = n-1-i;
        if(cnt[0]>0){
            s[i] = s[comp] = '0';
            cnt[0]-=2;
        } else {
            s[i] = s[comp] = '1';
            cnt[1]-=2;
        }
    }
    cout << s << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}