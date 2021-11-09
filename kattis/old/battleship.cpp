#include <bits/stdc++.h>
using namespace std;

/*
    0,0 0,1 0,2
    1,0 1,1 1,2
    2,0 2,1 2,2

    0,2 1,2 2,2
    0,1 1,1 2,1
    0,0 1,0 2,0
*/

bool shoot(int & i, int & j, set< pair<int,int> > & s){
    pair<int,int> p = {i, j};
    if(s.count(p)){
        s.erase(p);
        return true;
    }
    return false;
}

void solve(){
    int w, h, n; cin >> w >> h >> n;
    vector<string> grid1(h), grid2(h);
    for(int i = 0; i < h; i++){
        cin >> grid1[i];
    }
    for(int i = 0; i < h; i++){
        cin >> grid2[i];
    }
    set< pair<int,int> > s1, s2;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid1[i][j]=='#') s1.insert(make_pair(i,j));
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid2[i][j]=='#') s2.insert(make_pair(i,j));
        }
    }
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        y[i] = h-1-y[i];
        // cout  << y[i] << ' ' << x[i] << '\n';
    }
    bool p1win = false, p2win = false;
    int shot = 0;
    while(shot<n){
        bool shootagain = true;
        while(shootagain && shot<n){
            shootagain = shoot(y[shot], x[shot], s2);
            // if(shootagain){
            //     cout << "p2 " << y[shot] << ' ' << x[shot] << endl;
            // }
            shot++;
            if(s2.empty()){
                p1win = true;
                break;
            }
        }

        shootagain = true;
        while(shootagain && shot<n){
            shootagain = shoot(y[shot], x[shot], s1);
            // if(shootagain){
            //     cout << "p1 " << y[shot] << ' ' << x[shot] << endl;
            // }
            shot++;
            if(s1.empty()){
                p2win = true;
                break;
            }
        }
        if(p1win || p2win) break;
    }
    if(p1win != p2win){
        if(p1win){
            cout << "player one wins\n";
        } else {
            cout << "player two wins\n";
        }
    } else {
        cout << "draw\n";
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