#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int> prev_flight(N, -1), dist(N, -INF), in_degree(N);
    vector<vector<int>> edge(N), backedge(N);

    for(int i = 0; i < M; i++){
        int a, b; 
        cin >> a >> b;
        a--, b--;
        in_degree[b]++;
        
        edge[a].push_back(b);
        backedge[b].push_back(a);
    }

    queue<int> q;
    for(int i = 0 ; i < N; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int next_node : edge[node]){
            if(--in_degree[next_node] == 0){
                q.push(next_node);
            }
        }

        int mx = -INF, mx_node = -1;
        for(int prev_node : backedge[node]){
            if(dist[prev_node] + 1 > mx){
                mx = dist[prev_node] + 1;
                mx_node = prev_node;
            }
        }

        dist[node] = mx;
        if(node == 0) dist[node] = 1;
        prev_flight[node] = mx_node;
    }

    // for(int i : dist){
    //     cout << i << ' ';
    // }
    // cout << "\n\n";

    stack<int> ans;
    int temp = N - 1;
    bool contains0 = false;

    // check that the flightpath contains nodes 1 and N
    while(temp != -1 && dist[temp] >= 0){
        ans.push(temp);
        temp = prev_flight[temp];
        if(temp == 0) contains0 = true;
    }

    if(contains0){
        cout << dist[N - 1] << '\n';
        while(!ans.empty()){
            cout << ans.top() + 1;
            ans.pop();
            if(!ans.empty()) cout << ' ';
        }
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}