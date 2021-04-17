#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int index = 0;
    int curr = 0;
    int res = 0;
    while(index < s.length()){
        if(s[index]=='R'){
            curr++;
        } else {
            curr = 0;
        }
        res = max(res,curr);
        index++;
    }
    cout << res << endl;
}