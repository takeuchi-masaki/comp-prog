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
    unordered_map<int,int> umap;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        umap[temp]++;
    }
    map<int,int> cnt;
    unordered_map<int, int> sum;
    int prev = 0;
    for(auto& [x,y]:umap){
        cnt[y]++;
    }
    for(auto& [x,y]:cnt){
        sum[x]=prev;
        prev+=x*y;
    }
    map<int,int>::reverse_iterator rit=cnt.rbegin();
    int res = sum[rit->first];
    pair<int,int> next = {rit->first, rit->second};
    rit++;
    for(rit; rit!=cnt.rend(); rit++){
        int curr = sum[rit->first] + (next.first - rit->first) * next.second;
        next = {rit->first, rit->first + next.first};
        res = min(res, curr);
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}