#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<vector<int>> color(3, vector<int>(4));
    for(auto& vi : color){
        for(int& i : vi){
            cin >> i;
        }
    }
    vector<int> mins(4, 1e9);
    int sum = 0;
    for(int col = 0; col < 4; col++){
        for(int printer = 0; printer < 3; printer++){
            mins[col] = min(mins[col], color[printer][col]);
        }
        sum += mins[col];
    }
    if(sum < 1e6){
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    sum = 1e6;
    for(int i : mins){
        if(i >= sum){
            cout << sum << ' ';
            sum = 0;
        } else {
            cout << i << ' ';
            sum -= i;
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}