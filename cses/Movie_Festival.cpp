#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> movies(n);
    for(int i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end());
    int ans = 1, prevEnd = movies[0].second;
    for(int i = 1; i < n; i++){
        pair<int,int> curr = movies[i];
        if(curr.first >= prevEnd){
            ans++;
            prevEnd = curr.second;
            continue;
        }
        prevEnd = min(prevEnd, curr.second);
    }
    cout << ans << '\n';
}