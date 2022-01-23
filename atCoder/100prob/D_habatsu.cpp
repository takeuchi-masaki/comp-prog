#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<bool>> know(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        know[a-1][b-1] = true;
        know[b-1][a-1] = true;
    }
    
    int ans = 0;
    for(int group = 0; group < (1<<n); group++){
        vector<int> incl;
        for(int bit = 0; bit < n; bit++){
            if(group>>bit&1){
                incl.push_back(bit);
            }
        }
        if(incl.size() <= ans) continue;
        bool ok = true;
        for(int p : incl){
            for(int p2 : incl){
                if(p == p2) continue;
                if(!know[p][p2]) {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) ans = max(ans, (int)incl.size());
    }
    cout << ans << '\n';
}