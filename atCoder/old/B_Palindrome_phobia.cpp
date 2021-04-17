#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count[3] = {};
    for(int i = 0; i < s.length(); i++){
        count[s[i]-'a']++;
    }
    bool ok = false;
    if(abs(count[0]-count[1])<=1
    && abs(count[0]-count[2])<=1
    && abs(count[1]-count[2])<=1 ) ok = true;
    cout << (ok?"YES":"NO");
}