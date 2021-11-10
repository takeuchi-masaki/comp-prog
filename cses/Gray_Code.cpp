#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int mask = 0; mask < (1<<n); mask++){
        int grayCode = mask ^ (mask >> 1);
        string s = "";
        for(int bit = 0; bit < n; bit++){
            if(grayCode >> bit & 1) s.push_back('1');
            else s.push_back('0');
        }
        cout << s << '\n';
    }
}