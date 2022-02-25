#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; 
    cin >> s;
    vector<int> cnt(3);
    for(char c : s){
        if(c == 'T') cnt[0]++;
        else if(c == 'C') cnt[1]++;
        else if(c == 'G') cnt[2]++;
    }
    
    int ans = 0, min_cnt = 1e9;
    for(int i : cnt){
        ans += pow(i, 2);
        min_cnt = min(min_cnt, i);
    }
    ans += min_cnt*7;
    cout << ans << '\n';
}