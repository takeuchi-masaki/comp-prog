#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    bool ok = false;
    string target = "2020";
    int tarL = 0, tarR = n-1;
    string res = "";
    while(tarL<4){
        if(s[tarL] == target[tarL]){
            res+=s[tarL];
            tarL++;
        } else {
            break;
        }
    }
    int tarI = target.size()-1;
    string res2="";
    while(tarR>tarL && res.size()+res2.size()<target.size()){
        if(s[tarR]==target[tarI]){
            res2=s[tarR]+res2;
            tarI--, tarR--;
        } else {
            break;
        }
    }
    // cout << res+res2 << endl;
    if(res.size()+res2.size()==target.size()){
        ok = true;
    }
    // ok = (res+res) == target;
    cout << (ok?"YES":"NO") << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }   
}