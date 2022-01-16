#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    string front = "", back = "";
    set<char> ss;
    for(char c : s){
        if(ss.count(c)){
            front.push_back(c);
            back.push_back(c);
            ss.erase(c);
        } else {
            ss.insert(c);
        }
    }
    for(char c : ss){
        back.push_back(c);
    }
    // reverse(back.begin(), back.end());
    cout << front << back << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}