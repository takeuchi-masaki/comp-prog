#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int&i:a) cin >> i;
    unordered_map<int, int> m;
    for(int i:a){
        if(m.count(i)){
            m[i]--;
            m[i-1]++;
            if(m[i] == 0) m.erase(i);
        } else {
            m[i-1]++;
        }
    }
    int ans = 0;
    for(pair<int, int> p:m) ans += p.second;
    cout << ans << endl;
}