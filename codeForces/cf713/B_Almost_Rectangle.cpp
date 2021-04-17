#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    vector<pair<int,int>> mark;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j]=='*'){
                mark.push_back(make_pair(i,j));
            }
        }
    }
    pair<int,int> p1 = mark[0], p2 = mark[1];
    if(p1.first!=p2.first && p1.second != p2.second){
        s[p1.first][p2.second] = s[p2.first][p1.second] = '*';
    } else {
        if(p1.first == p2.first){
            if(p1.first-1>=0){
                s[0][p1.second] = s[0][p2.second] = '*';
            } else {
                int y = p1.first+1;
                s[y][p1.second] = s[y][p2.second] = '*';
            }
        } else {
            if(p1.second-1>=0){
                s[p1.first][0] = s[p2.first][0] = '*';
            } else {
                int x = p1.second+1;
                s[p1.first][x] = s[p2.first][x] = '*';
            }
        }
    }
    // print ans
    for(int i = 0; i < n; i++){
        cout << s[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}