#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.size(), ab = 0, ba = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == 'a'){
            if(s[i+1] == 'b') ab++;
        } else {
            if(s[i+1] == 'a') ba++;
        }
    }
    if(ab == ba){
        cout << s << '\n';
        return;
    }
    //difference cannot be larger than 1
    if(s[n-1] == 'a'){
        s[n-1] = 'b';
    } else {
        s[n-1] = 'a';
    }
    cout << s << '\n';
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