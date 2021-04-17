#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> q(n);
    set<int> used;
    for(int i = 1; i<=n; i++) used.insert(i);
    for(auto& i:q){
        cin>>i; 
        used.erase(i);
    }
    set<int> used2(used);
    int prev = q[0];
    cout << prev << " ";
    for(int i = 1; i<n; i++){
        while(i<n && q[i]==prev){
            cout << *used.begin() << " ";
            used.erase(*used.begin());
            i++;
        }
        if(i==n) break;
        prev = q[i];
        cout << prev << " ";
    }
    cout << "\n";

    prev = q[0];
    cout << prev << " ";
    for(int i = 1; i<n; i++){
        while(i<n && q[i]==prev){
            set<int>::iterator it = used2.lower_bound(q[i]);
            it--;
            cout << *it << " ";
            used2.erase(*it);
            i++;
        }
        if(i==n) break;
        prev = q[i];
        cout << prev << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}