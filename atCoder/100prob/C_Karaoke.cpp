#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<long long>> score(n, vector<long long>(m));
    for(auto& vll : score){
        for(auto& ll : vll) cin >> ll;
    }
    long long ans = 0;
    for(int s1 = 0; s1 < m; s1++){
        for(int s2 = s1 + 1; s2 < m; s2++){
            long long curr = 0;
            for(int person = 0; person < n; person++){
                curr += max(score[person][s1], score[person][s2]);
            }
            ans = max(ans, curr);
        }
    }
    cout << ans << '\n';
}