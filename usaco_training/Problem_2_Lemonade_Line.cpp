#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("lemonade.in","r",stdin); freopen("lemonade.out","w",stdout);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for(int i : a){
        if(ans <= i) ans++;
    }
    cout << ans << '\n';
}