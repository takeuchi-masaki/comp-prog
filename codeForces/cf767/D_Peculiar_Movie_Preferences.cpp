#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int n; cin >> n;
    unordered_set<string> m, need;
    vector<string> vs(n);
    for(string& s : vs) cin >> s;

    for(string& s : vs){
        if(s.size() == 1) return true;
        string rev = s;
        reverse(rev.begin(), rev.end());
        if(m.count(rev)) return true;
        if(s.size() == 2){
            if(s[0] == s[1]) return true;
            if(need.count(s)) return true;
        } else if(s.size() == 3){
            if(s[0] == s[2]) return true;
            string sub = s.substr(1, 2);
            reverse(sub.begin(), sub.end());
            if(m.count(sub)) return true;
            sub = s.substr(0, 2);
            reverse(sub.begin(), sub.end());
            need.insert(sub);
        }
        m.insert(s);
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}