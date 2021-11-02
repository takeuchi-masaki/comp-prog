#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<long long> a(n);
    for(long long&i:a) cin >> i;

    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        if(a[i] > 0) pq.push(make_pair(a[i], i));
    }

    vector<pair<int,int>>vp;
    while(!pq.empty()){
        pair<int,int> p1 = pq.top(); pq.pop();
        if(pq.empty()) break;
        pair<int,int> p2 = pq.top(); pq.pop();
        vp.push_back(make_pair(p1.second, p2.second));
        p1.first--;
        p2.first--;
        if(p1.first > 0) pq.push(p1);
        if(p2.first > 0) pq.push(p2);
    }

    cout << vp.size() << '\n';
    for(auto p:vp){
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}