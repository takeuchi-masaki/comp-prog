#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    set<char> st;
    int ans = 0;
    for(char c : s){
        if(st.count(c)){
            ans += st.size() - 1;
            st.clear();
        } else {
            st.insert(c);
        }
    }
    ans += st.size();
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