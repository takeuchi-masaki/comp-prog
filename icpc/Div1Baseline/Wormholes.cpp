#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve(){
    int p; cin >> p;
    unordered_map<string, int> m;
    vector<int> x(p), y(p), z(p);
    for(int i = 0; i < p; i++){
        string name;
        cin >> name >> x[i] >> y[i] >> z[i];
        m[name] = i;
    }
    vector<vector<double>> dist(p, vector<double>(p, INF));
    for(int i = 0; i < p; i++){
        for(int j = i + 1; j < p; j++){
            long long xDiff = x[i] - x[j];
            xDiff *= xDiff;
            long long yDiff = y[i] - y[j];
            yDiff *= yDiff;
            long long zDiff = z[i] - z[j];
            zDiff *= zDiff;
            dist[i][j] = sqrtl(xDiff + yDiff + zDiff);
            dist[j][i] = dist[i][j];
        }
    }
    for(int i = 0; i < p; i++){
        dist[i][i] = 0;
    }

    int w; cin >> w;
    for(int i = 0; i < w; i++){
        string a, b; cin >> a >> b;
        dist[m[a]][m[b]] = 0;
    }

    for(int k = 0; k < p; k++){
        for(int i = 0; i < p; i++){
            for(int j = 0; j < p; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        string a, b; cin >> a >> b;
        cout << "The distance from " << a << " to " << b << " is ";
        cout << fixed << setprecision(0) << round(dist[m[a]][m[b]]) << " parsecs.\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("wormhole.in","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}