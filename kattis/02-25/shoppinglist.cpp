#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    set<string> curr_set;
    for(int j = 0; j < m; j++){
        string s; cin >> s;
        curr_set.insert(s);
    }
    for(int i = 1; i < n; i++){
        set<string> next_set;
        for(int j = 0; j < m; j++){
            string s; cin >> s;
            if(curr_set.count(s)){
                next_set.insert(s);
            }
        }
        curr_set = move(next_set); // move semantics
    }
    cout << curr_set.size() << '\n';
    for(string s : curr_set){ // set is already in order
        cout << s << '\n';
    }
}