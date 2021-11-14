#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unordered_set<int> sol;
    for(int a = 1; a < 400; a++){
        for(int b = 1; b < 400; b++){
            int ans = 4 * a * b + 3 * a + 3 * b;
            if(ans > 1000) break;
            sol.insert(ans);
        }
    }

    int n; cin >> n;
    int ans = n;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        if(sol.count(num)) ans--;
    }
    cout << ans << '\n';
}