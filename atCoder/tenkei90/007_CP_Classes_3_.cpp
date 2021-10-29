#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> classes(n);
    for(int&i:classes)cin>>i;
    sort(classes.begin(), classes.end());
    // for(int i:classes) cout << i << ' ';
    // cout << '\n';
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int rating; cin >> rating;
        int pos = upper_bound(classes.begin(), classes.end(), rating)-classes.begin();
        // cout << rating << ' ' << pos << '\n';
        if(pos == n){
            cout << abs(rating-classes[n-1]) << '\n';
        } else if(pos == 0) {
            cout << abs(rating-classes[0]) << '\n';
        } else {
            cout << min(abs(rating-classes[pos]), abs(rating-classes[pos-1])) << '\n';
        }
    }
}