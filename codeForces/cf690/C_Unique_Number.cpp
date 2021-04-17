#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    cin >> x; // sum of digits
    bool ok = true;
    int digits = 0, sum=0, add=9;
    string res = "";
    while(sum<x){
        if(add < 0) {
            ok = false; break;
        }
        sum+=add;
        res=to_string(add)+res;
        add--, digits++;
    }
    // cout << digits << endl;
    int lastNum = res[0]-'0';
    lastNum-=sum-x;
    res[0]=lastNum+'0';
    cout << (ok?res:"-1") << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}