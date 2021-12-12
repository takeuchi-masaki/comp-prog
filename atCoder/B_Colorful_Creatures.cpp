#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> vi(n);
    for(int i = 0; i < n; i++){
        // {starting size, idx(color)}
        cin >> vi[i].first;
        vi[i].second = i;
    }
    sort(vi.begin(), vi.end());
    vector<long long> prefix(n);
    prefix[0] = vi[0].first;
    for(int i = 1; i < n - 1; i++){
        prefix[i] = prefix[i - 1] + vi[i].first;
    }
    long long ans = 1;
    for(int i = n - 2; i >= 0; i--){
        // cout << prefix[i]*2 << ' ' << vi[i + 1].first << '\n';
        if(prefix[i] * 2 >= vi[i + 1].first){
            ans++;
        } else {
            break;
        }
    }
    cout << ans << '\n';
}