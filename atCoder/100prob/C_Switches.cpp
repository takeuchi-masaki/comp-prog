#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> bulbsLit(n);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int sw; cin >> sw;
            sw--;
            bulbsLit[sw].push_back(i);
        }
    }
    vector<int> mod2(m);
    for(int& i : mod2) cin >> i;

    int ans = 0;
    for(int mask = 0; mask < (1<<n); mask++){
        vector<int> cnt(m);
        for(int sw = 0; sw < n; sw++){
            if(mask>>sw&1){
                for(int i : bulbsLit[sw]){
                    cnt[i]++;
                }
            }
        }
        bool ok = true;
        for(int bulb = 0; bulb < m; bulb++){
            if(cnt[bulb] % 2 != mod2[bulb]){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << '\n';
}