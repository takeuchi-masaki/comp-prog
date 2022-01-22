#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 0; i < 1000; i++){
        string t = to_string(i);
        int padZero = 3 - t.size();
        string zero; zero.append(padZero,'0');
        t = zero + t;

        int found = 0, idx = 0;
        while(found < 3 && idx < n){
            if(s[idx] == t[found]) found++;
            idx++;
        }
        if(found == 3) ans++;
    }
    cout << ans << '\n';
}