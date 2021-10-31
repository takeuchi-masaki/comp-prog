#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    for(char c:s){
        if(c >= 'a' && c <= 'z'){
            cout << "error\n";
            return 0;
        }
    }
    int n = stoi(s);
    cout << n*2 << endl;
}