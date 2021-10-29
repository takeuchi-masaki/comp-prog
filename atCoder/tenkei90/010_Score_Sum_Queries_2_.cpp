#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector< vector<int> > count(2, vector<int>(n));
    int c, p; cin >> c >> p;
    c--;
    count[c][0]+=p;
    for(int i = 1; i < n; i++){
        cin >> c >> p;
        c--;
        count[0][i] = count[0][i-1];
        count[1][i] = count[1][i-1];
        count[c][i] += p;
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l-=2, r--;
        cout << count[0][r]-(l!=-1?count[0][l]:0)
        << ' ' << count[1][r]-(l!=-1?count[1][l]:0) << '\n';
    }
}