#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    vector<int> cnt(3);
    for(char c : s){
        if(c == 'T') cnt[0]++;
        else if(c == 'C') cnt[1]++;
        else if(c == 'G') cnt[2]++;
    }

    int minCnt = 1e9, ans = 0;
    for(int i : cnt){
        minCnt = min(minCnt, i);
        ans += pow(i, 2);
    }
    ans += minCnt * 7;
    cout << ans << '\n';
}