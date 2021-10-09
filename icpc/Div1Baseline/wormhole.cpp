#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int INF = 1e9;

void solve(){
    int p, w, q;
    unordered_map< string, int > map;
    cin >> p;
    vector< vector<int> > dist(p, vector<int>(p, INF)), coords(p);
    for(int i = 0; i < p; i++){        
        string name; 
        vector<int> coord(3);
        cin >> name >> coord[0] >> coord[1] >> coord[2];
        // cout << name << ' ' << coord[0] << ' ' << coord[1] << ' ' << coord[2] << endl;
        map[name] = i;
        coords[i] = coord;
    }

    // euclidean distance
    for(int i = 0; i < p-1; i++){
        for(int j = i+1; j < p; j++){
            long long sum = 0;
            for(int n = 0; n < 3; n++){
                long long d = coords[i][n]-coords[j][n];
                d *= d;
                sum += d;
            }
            sum = sqrt(sum);
            dist[i][j] = sum;
            dist[j][i] = sum;
        }
    }

    cin >> w;
    for(int i = 0; i < w; i++){
        string planet1, planet2;
        cin >> planet1 >> planet2;
        // cout << planet1 << ' ' << planet2 << endl;
        dist[ map[planet1] ][ map[planet2] ] = 0;
    }

    for(int k = 0; k < p; k++){
        for(int i = 0; i < p; i++){
            for(int j = 0; j < p; j++){
                dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
            }
        }
    }

    cin >> q;
    for(int i = 0; i < q; i++){
        string planet1, planet2;
        cin >> planet1 >> planet2;
        // cout << planet1 << ' ' << planet2 << endl;
        cout << "The distance from " << planet1 << " to " << planet2 << " is " 
             << dist[ map[planet1] ][ map[planet2] ] << " parsecs.\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("wormhole.in","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": \n";
        solve();
    }
}