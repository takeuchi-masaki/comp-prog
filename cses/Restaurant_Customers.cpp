#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        int arrive, leave; cin >> arrive >> leave;
        m[arrive]++;
        m[leave]--;
    }
    int curr = 0, ans = 0;
    for(pair<int,int> p : m){
        curr += p.second;
        ans = max(ans, curr);
    }
    cout << ans << '\n';
}