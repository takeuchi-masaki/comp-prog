#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int res = 0,curr=0;
    for(int i = 0; i < n; i++){
        if(s[i]=='I'){
            curr++;
        } else {
            curr--;
        }
        res = max(res,curr);
    }
    cout << res << endl;
}