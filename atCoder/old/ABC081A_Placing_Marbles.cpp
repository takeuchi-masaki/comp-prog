#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int ans = 0;
    for(char c:s){
        if(c == '1') ans++;
    }
    cout << ans << endl;
}