#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void solve(){
    int n;
    cin >> n;
    unordered_map<int,int> nums;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        nums[temp]++;
    }
    map<int,int> cnt;
    for(auto& [x,y]:nums){
        cnt[y]++;
    }
    int res = n;
    int l = 0, r = n, rCnt = cnt.size();
    for(auto [x,y]:cnt){
        res = min(res, l + r - rCnt*x);
        l+=x*y;
        r-=x*y;
        rCnt-=y;
    }
    cout << res << '\n';
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}