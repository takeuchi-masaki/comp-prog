#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, weight;
    Edge(int uu, int vv, int ww){
        u = uu;
        v = vv;
        weight = ww;
    }
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int kruskal(vector<Edge>& edges, int n){
    // int n;
    int cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }

    return cost;
}

void solve(){
    int n, p; cin >> n >> p;

    vector<vector<int>> pairs(n, vector<int>(n, -1));

    vector<pair<int,int>> a(n);
    for(auto& i:a)cin>>i.first;
    for(int i = 0; i < n; i++){
        a[i].second = i;
    }
    sort(a.begin(),a.end());

    // int prev = a[0].first, prevStart = 0;
    // for(int i = 1; i < n; i++){
    //     if(a[i].first==prev){ continue; }
    //     if(i-prevStart>1){
    //         for(int j = prevStart; j < i-1; j++){
    //             for(int k = j+1; k <= i-1; k++){
    //                 pair<int,int> p1 = a[j], p2 = a[k];
    //                 // edges.push_back( Edge(p1.second, p2.second, prev) );
    //                 pairs[p1.second][p2.second] = min(pairs[p1.second][p2.second], prev);
    //             }
    //         }
    //     }
    //     prev = a[i].first;
    // }
    // if(n-prevStart>1){
    //     for(int j = prevStart; j < n-1; j++){
    //         for(int k = j+1; k <= n-1; k++){
    //             pair<int,int> p1 = a[j], p2 = a[k];
    //             // edges.push_back( Edge(p1.second, p2.second, prev) );
    //             pairs[p1.second][p2.second] = min(pairs[p1.second][p2.second], prev);
    //         }
    //     }
    // }

    for(int i = 0; i < n; i++){
        // if(a[i].first>p) break;
        for(int j = a[i].first; j<=a[n-1].first; j+=a[i].first){
            auto it1 = lower_bound(a.begin(), a.end(), make_pair(j, -1));
            auto it2 = upper_bound(a.begin(), a.end(), make_pair(j, n+1));
            if(it2-it1 == 0) continue;
            for(it1; it1!=it2; it1++){
                pairs[a[i].second][it1->second] = max(pairs[a[i].second][it1->second], a[i].first);
            }
        }
    }

    vector<Edge> edges;
    for(int i = 0; i < n-1; i++){
        // edges.push_back(Edge(i, i+1, p));
        if(pairs[i][i+1]==-1){
            pairs[i][i+1] = p;
            continue;
        }
        pairs[i][i+1] = min(pairs[i][i+1], p);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(pairs[i][j] != -1){
                edges.push_back(Edge(i, j, pairs[i][j]));
            }
        }
    }

    cout << kruskal(edges, n) << '\n';
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