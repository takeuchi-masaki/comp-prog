#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.size();
    bool foundOk = false;
    for(int i = 0; i < n; i++){
        bool ok = true;
        for(int cnt = 0; cnt < n; cnt++){
            int j = (i + cnt) % n;
            // cout << s[cnt] << ' ' << rev[j] << '\n';
            // cout << j << ' ';
            if(s[cnt] != rev[j]) {
                ok = false;
                break;
            }
        }
        cout << '\n';
        if(ok){
            foundOk = true;
            break;
        }
    }
    cout << (foundOk ? "1\n" : "0\n");
}