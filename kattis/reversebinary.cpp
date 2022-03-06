#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string rev_bin = "";
    while(n > 0){
        if(n&1) rev_bin.push_back('1');
        else rev_bin.push_back('0');
        n>>=1;
    }
    // cout << rev_bin << '\n';

    int ans = 0;
    for(int i = 0; i < rev_bin.size(); i++){
        if(rev_bin[i] == '1'){
            ans += (1<<(rev_bin.size() - 1 - i));
        }
    }
    cout << ans << '\n';
}