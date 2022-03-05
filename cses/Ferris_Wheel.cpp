#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, maxW; cin >> n >> maxW;
    vector<int> child(n);
    for(int& i : child) cin >> i;
    sort(child.begin(), child.end());
    int l = 0, r = n - 1;
    int ans = 0;
    while(r - l >= 0){
        ans++;
        if(r == l) break;
        if(child[l] + child[r] <= maxW){
            r--;
            l++;
        } else {
            r--;
        }
    }
    cout << ans << '\n';
}