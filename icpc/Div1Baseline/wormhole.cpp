#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void solve(){
    int p, w, q;
    unordered_map< string, vector<int> > map;
    cin >> p;
    for(int i = 0; i < p; i++){        
        string name; 
        vector<int> coord(3);
        cin >> name >> coord[0] >> coord[1] >> coord[2];
        // cout << name << ' ' << coord[0] << ' ' << coord[1] << ' ' << coord[2] << endl;
        map.insert(name, coord);
    }

    cin >> w;
    for(int i = 0; i < w; i++){
        string planet1, planet2;
        cin >> planet1 >> planet2;
        cout << planet1 << ' ' << planet2 << endl;
    }

    cin >> q;
    for(int i = 0; i < q; i++){
        string planet1, planet2;
        cin >> planet1 >> planet2;
        cout << planet1 << ' ' << planet2 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": \n";
        solve();
    }
}