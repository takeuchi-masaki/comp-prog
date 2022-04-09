#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = (int)s.size();

    string ans{};
    ans.push_back(s[0]);
    int eq = 0;
    for(int i = 1; i < n; i++){
        if(s[i - 1] == s[i]){
            eq++;
        } else {
            if(s[i - 1] < s[i]){
                for(int j = 0; j < eq + 1; j++){
                    ans.push_back(s[i - 1]);
                }
            }
            eq = 0;
        }
        ans.push_back(s[i]);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}