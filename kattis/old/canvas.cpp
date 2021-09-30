#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    long long total = 0;
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    for(int i = 0; i < n; i++){
        long long c; cin >> c;
        pq.push(c);
    }
    while(pq.size()>=2){
        long long curr = 0;
        curr += pq.top();
        pq.pop();
        curr += pq.top();
        pq.pop();
        pq.push(curr);
        total += curr;
    }
    cout << total << endl;
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