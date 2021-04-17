#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, W; cin >> n >> W;
    vector<int> cnt(21);
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        int pow = log2(temp);
        cnt[pow]++;
    }
    // for(int i:cnt) cout << i << " ";
    // cout << '\n';
    int res = 0;
    map<int,int> box;
    box[W]+=n;
    for(int i = cnt.size()-1; i >= 0; i--){
        int num = (1<<i);
        while(cnt[i]>0){
            auto it = box.lower_bound(num);
            // cout << it->first << ' ' << it->second << '\n';
            cnt[i]--;
            if(box[it->first]==1) box.erase(it->first);
            else box[it->first]--;
            box[it->first - num]++;
        }
    }
    for(pair<int,int> p:box){
        if(p.first==W) break;
        res += p.second;
    }
    cout << res << '\n';
    // cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}