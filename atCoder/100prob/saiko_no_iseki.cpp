#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> xy(n);
    set<pair<int,int>> s;
    for(int i = 0; i < n; i++){
        cin >> xy[i].first >> xy[i].second;
        s.insert({xy[i].first, xy[i].second});
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            auto [x1, y1] = xy[i];
            auto [x2, y2] = xy[j];
            int xDiff = x2 - x1, yDiff = y2 - y1;
            pair<int,int> p1 = {
                x1 + yDiff,
                y1 - xDiff
            };
            pair<int,int> p2 = {
                x2 + yDiff,
                y2 - xDiff
            };
            // pair<int,int> p3 = {
            //     x1 - yDiff,
            //     y1 + xDiff
            // };
            // pair<int,int> p4 = {
            //     x2 - yDiff,
            //     y2 + xDiff
            // };
            if(s.count(p1) && s.count(p2)){
                int curr = xDiff*xDiff + yDiff*yDiff;
                ans = max(ans, curr);
            }
        }
    }
    cout << ans << '\n';
}