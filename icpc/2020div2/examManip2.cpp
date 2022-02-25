#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
vector<string> tests;

void dfs(vector<bool> key){
    if(key.size() < k){
        for(int i = 0; i < 2; i++){
            key.push_back(i);
            dfs(key);
            key.pop_back();
        }
        return;
    }
    int lowest = 1e9;
    for(string t : tests){
        int curr = 0;
        for(int q = 0; q < k; q++){
            bool solution = (t[q] == 'T');
            if(solution == key[q]) curr++;
        }
        lowest = min(lowest, curr);
    }
    ans = max(ans, lowest);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    tests.resize(n);
    for(string& s : tests) cin >> s;

    vector<bool> key;
    dfs(key);
    cout << ans << '\n';
}