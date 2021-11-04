#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    set<string> names;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        if(names.emplace(s).second){
            cout << i << '\n';
        }
    }
}