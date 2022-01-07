#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
    int k; cin >> k;
    string a, b; cin >> a >> b;
    cout << a << '\n' << b << '\n';
    int same = 0, n = a.size();
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) same++;
    }
    int diff = n - same;
    int ans = min(same, k);
    if(k > same) diff -= k - same; 
    ans += diff;

    cout << n << '\n';
    cout << same << '\n';
    cout << ans << '\n';
}