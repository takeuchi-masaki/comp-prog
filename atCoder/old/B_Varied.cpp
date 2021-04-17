#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int letters[26]={};
    for(int i = 0; i < s.length(); i++){
        letters[(int)s[i]-(int)'a']++;
    }
    bool ok = true;
    for(int i:letters){
        if(i>1){
            ok = false;
            break;
        }
    }
    cout << (ok?"yes":"no");
}