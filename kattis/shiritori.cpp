#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    bool p1loss = false, p2loss = false;
    set<string> used;
    string prev; cin >> prev;
    used.insert(prev);
    for(int i = 1; i < n; i++){
        string s; cin >> s;
        if(used.count(s) || s[0] != prev[prev.size()-1]){
            if(i&1){
                p2loss = true;
            } else {
                p1loss = true;
            }
            break;
        }
        used.insert(s);
        prev = s;
    }
    if(!p1loss && !p2loss){
        cout << "Fair Game\n";
    } else {
        cout << (p1loss?"Player 1 ":"Player 2 ") << "lost\n";
    }
}