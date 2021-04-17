#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length(), zero = 0, one = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='0'){
            zero++;
        } else {
            one++;
        }
    }
    int res = min(zero,one)*2;
    cout << res << endl;
}