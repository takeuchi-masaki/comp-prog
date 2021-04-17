#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = (int)'a', z = (int) 'z';
    int CCnt = 0;
    bool ok = true;
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        if(i == 0){
            if(c == 'A'){
                continue;
            } else {
                ok = false;
                break;
            }
        } else {
            if(c == 'C'){
                if(i < 2 || i > s.length()-2){
                    ok = false;
                    break;
                }
                if(++CCnt>1){
                    ok = false;
                    break;
                }
            } else {
                if(c>=a && c<=z){
                    continue;
                } else {
                    ok = false;
                    break;
                }
            }
        }
    }
    if(CCnt != 1) ok = false;
    cout << (ok?"AC":"WA") << endl;
}