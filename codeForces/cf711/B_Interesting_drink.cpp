#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> x(n);
    for(int& i:x)cin>>i;
    sort(x.begin(),x.end());
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int m; cin >> m;
        auto it = upper_bound(x.begin(),x.end(), m);
        cout << (it-x.begin()) << '\n';
    }
}