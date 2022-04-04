#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;

    int cntS = 0, remove = 0;
    for(char c : s){
        if(c == 'S') cntS++;
        else if(cntS > 0){
            cntS--;
            remove++;
        }
    }
    remove<<=1;
    cout << s.size() - remove << '\n';
}