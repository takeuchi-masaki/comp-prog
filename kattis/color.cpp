#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, c, k; cin >> n >> c >> k;
    vector<int> color(n);
    for(int & i : color) cin >> i;
    sort(color.begin(), color.end());
    
    int upperLimit = color[0] + k, currCapacity = 1, ans = 1;
    for(int i = 1; i < n; i++){
        if(currCapacity == c || color[i] > upperLimit){
            ans++;
            currCapacity = 1;
            upperLimit = color[i] + k;
        } else {
            currCapacity++;
        }
    }
    cout << ans << '\n';
}