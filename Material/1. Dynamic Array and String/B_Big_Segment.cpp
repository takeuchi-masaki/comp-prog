#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> segments(n);
    int minN = 1e9+5, maxN = 0;
    for(auto&p : segments){
        cin >> p.first >> p.second;
        minN = min(minN, p.first);
        maxN = max(maxN, p.second);
    }
    int i = 1;
    bool found = false;
    for(auto p:segments){
        if(p.first == minN && p.second == maxN){
            cout << i << endl;
            found = true;
            break;
        }
        i++;
    }
    if(!found) cout << -1 << endl;
}