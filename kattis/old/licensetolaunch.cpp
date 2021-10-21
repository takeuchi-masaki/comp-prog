#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    // int ans = 0, minJunk = 1e9;
    vector<int> junk(n);
    for(int&i:junk) cin >> i;
    cout << min_element(junk.begin(), junk.end()) - junk.begin() << endl;
    // for(int i = 0; i < n; i++){
    //     if(junk[i] < minJunk) {
    //         ans = i;
    //         minJunk = junk[i];
    //     }
    // }
    // cout << ans << endl;
}