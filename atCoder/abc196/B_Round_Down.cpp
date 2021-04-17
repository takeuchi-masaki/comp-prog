#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x;
    cin >> x;
    string res = "";
    for(int i = 0; i < x.length(); i++){
        if(x[i]=='.'){
            break;
        }
        res+=x[i];
    }
    cout << res << endl;
}