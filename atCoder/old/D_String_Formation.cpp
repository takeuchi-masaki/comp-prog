#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s; int q;
    cin >> s >> q;
    deque<char> dq;
    for(int i = 0; i < s.size(); i++){
        dq.emplace_back(s[i]);
    }
    bool rev = false; // reversed
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t==1){
            // reverse(s.begin(),s.end());
            rev = !rev;
        } else {
            int f; char c;
            cin >> f >> c;
            f = 2-f;
            if(f==!rev){
                dq.push_front(c);
            } else {
                dq.push_back(c);
            }
        }
    }
    if(rev){
        reverse(dq.begin(),dq.end());
    }
    for(char c:dq) {
        cout << c;
    }
    cout << '\n';
}