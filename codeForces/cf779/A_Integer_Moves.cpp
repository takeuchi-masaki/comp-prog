#include <bits/stdc++.h>
using namespace std;

set<int> perf_sq;

void solve(){
    int x, y; cin >> x >> y;
    if(x == 0 && y == 0){
        cout << "0\n";
        return;
    }
    int dist_2 = x*x + y*y;
    if(perf_sq.count(dist_2)){
        cout << "1\n";
    }
    else {
        cout << "2\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    for(int i = 1; i*i <= 5000; i++){
        perf_sq.insert(i*i);
    }

    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}