#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    set<string> st;
    for(int j = 0; j < m; j++){
        string s; cin >> s;
        st.insert(s);
    }
    for(int i = 1; i < n; i++){
        set<string> next_st;
        for(int j = 0; j < m; j++){
            string s; cin >> s;
            if(st.count(s)){
                next_st.insert(s);
            }
        }
        st = move(next_st);
    }
    cout << st.size() << '\n';
    for(string s : st){
        cout << s << '\n';
    }
}