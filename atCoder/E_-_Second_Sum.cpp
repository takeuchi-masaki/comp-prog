#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a){
    for(int i: a) cout << i << ' ';
    cout << '\n';
    int n = a.size();
    int ans = 0;
    map<int,int> added;
    for(int l = 0; l < n - 1; l++){
        for(int r = l + 1; r < n; r++){
            int mx1 = -1, mx2 = -1;
            for(int i = l; i <= r; i++){
                if(a[i] > mx1){
                    mx2 = mx1;
                    mx1 = a[i];
                } else if(a[i] > mx2){
                    mx2 = a[i];
                }
            }
            added[mx2]++;
            ans += mx2;
        }
    }
    for(auto& [num, cnt]: added){
        cout << num << ' ' << cnt << '\n';
    }
    cout << ans << '\n' << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    freopen("out.txt","w",stdout);
    
    vector<int> a(5);
    iota(a.begin(), a.end(), 1);
    do {
        solve(a);
    } while(next_permutation(a.begin(), a.end()));
}