#include <bits/stdc++.h>
using namespace std;

bool run(string& s, int start, int end){
    unordered_set<char> minos;
    for(int i = start; i < end; i++){
        if(minos.size() == 7) minos.clear();
        if(!minos.insert(s[i]).second){
            return false;
        }
    }
    return true;
}

void solve(){
    string s; cin >> s;
    for(int start = 0; start < 7 && start < s.size(); start++){
        if(run(s, 0, start) && run(s, start, s.size())){
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}