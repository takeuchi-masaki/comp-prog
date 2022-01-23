#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int m; cin >> m;
    vector<pair<int,int>> c(m);
    for(int i = 0; i < m; i++){
        cin >> c[i].first >> c[i].second;
    }

    int n; cin >> n;
    vector<pair<int,int>> a(n);
    set<pair<int,int>> s;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        s.insert(a[i]);
    }

    for(auto [x, y] : a){
        int xDiff = x - c[0].first;
        int yDiff = y - c[0].second;
        bool ok = true;
        for(int j = 1; j < m; j++){
            pair<int,int> p = {
                c[j].first + xDiff,
                c[j].second + yDiff
            };
            if(!s.count(p)) {
                ok = false;
                break;
            }
        }
        if(ok){
            cout << xDiff << ' ' << yDiff << '\n';
            return 0;
        }
    }
}