#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> neg, pos;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        if(num < 0) neg.push_back(-num);
        else if(num > 0) pos.push_back(num);
        else k--;
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    int ans = 1e9;
    for(int i = 0; i <= k; i++){
        int idxNeg = i - 1;
        int idxPos = k - i - 1;
        if(idxNeg >= (int)neg.size()) continue;
        if(idxPos >= (int)pos.size()) continue;
        int costNeg = 0;
        int costPos = 0;
        if(idxNeg >= 0) costNeg = neg[idxNeg];
        if(idxPos >= 0) costPos = pos[idxPos];
        int currCost = costNeg + costPos + min(costNeg, costPos);
        ans = min(ans, currCost);
    }
    cout << ans << '\n';
}