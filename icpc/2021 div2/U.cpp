#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.size();
    bool ans = false;
    for(int cnt = 0; cnt < n; cnt++){
        bool ok = true;
        for(int i = 0; i < n; i++){
            int j = (i + cnt) % n;
            // cout << s[i] << ' ' << rev[j] << '\n';
            // cout << j << ' ';
            if(s[i] != rev[j]) {
                ok = false;
                break;
            }
        }
        // cout << '\n';
        if(ok){
            ans = true;
            break;
        }
    }
    cout << (ans ? "1\n" : "0\n");
}