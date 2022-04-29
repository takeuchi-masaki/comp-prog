#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<pair<int,int>> directions = {
        {1, 0},
        {0, -1},
        {-1, 0},
        {0, 1}
    };

    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0, dir = 0;
    for(char c: s){
        if(c == 'S'){
            x += directions[dir].first;
            y += directions[dir].second;
        } else {
            dir = (dir + 1) % 4;
        }
    }
    cout << x << ' ' << y << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    solve();
}