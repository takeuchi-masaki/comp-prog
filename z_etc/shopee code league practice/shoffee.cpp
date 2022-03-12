#include <bits/stdc++.h>
using namespace std;


vector<int> bit(2e5);

void add(int idx, int delta){
    for( ; idx < bit.size(); idx += idx & -idx){
        bit[idx] += delta;
    }
}

int sum(int idx){
    int ret = 0;
    for( ; idx > 0; idx -= idx & -idx){
        ret += bit[idx];
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n), prefix(n+1);
    for(int& i : a) {
        cin >> i;
        i -= k;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = a[i - 1] + prefix[i - 1];
        if(prefix[i] >= 0) ans++;
    }

    // rank the prefixes as positive values from 1, 1 being the lowest
    vector<int> nums = prefix;
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for(int i = 1; i <= n; i++){
        prefix[i] = lower_bound(nums.begin(), nums.end(), prefix[i]) - nums.begin() + 1;
    }

    // bit counts all the prefixes lower than the current 
    for(int i = 1; i <= n; i++){
        ans += sum(prefix[i]);
        add(prefix[i], 1);
    }
    cout << ans << '\n';
}