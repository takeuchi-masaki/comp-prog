#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// cp-algorithms sparse graph dijkstra implementation
const int INF = 1000000000;
vector< vector < pair<int, int> > > adj;

/**
 *  @s start index
 *  @d vector of distances
 *  @p previous node
 */
void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set< pair<int, int> > q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    while( true ){
        // node, edge, queries, start(0 index)
        int n, m, q, s;
        cin >> n >> m >> q >> s;
        if(n == 0) break;
        adj = vector< vector <pair <int, int> > >(n);
        vector<int> dist(n), p(n);
        for(int edges = 0; edges < m; edges++){
            int n1, n2, w; cin >> n1 >> n2 >> w;
            adj[n1].push_back(make_pair(n2, w));
            // adj[n2].push_back(make_pair(n1, w));
        }
        dijkstra(s, dist, p);
        for(int i = 0; i < q; i++){
            int query;
            cin >> query;
            if(dist[query] == INF) {
                cout << "Impossible\n";
            } else {
                cout << dist[query] << '\n';
            }
        }
        cout << '\n';
    }
}