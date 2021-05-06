#include <bits/stdc++.h>
using namespace std;

struct Q{
  int start, currDist;
  Q(int st, int dst){
    start = st, currDist = dst;
  }
};

int main(){
    while(true){
        int n, m, a, k; cin >> n >> m >> a >> k;
        if(n == m == a == k == 0) break;
        vector< vector<int> > grid(n+1, vector<int>(n+1));
        for(int i = 0; i < m; i++){ // roads
            int t1, t2, d; cin >> t1 >> t2 >> d;
            grid[t1][t2] = d;
            grid[t2][t1] = d;
        }
        vector< vector<int> > adj(n+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]!=0) adj[i].push_back(j);
            }
        }
        vector<bool> alien(n+1);
        vector<bool> safe(n+1, true);
        int safecnt = n;
        for(int i = 0; i < a; i++){ // alien bases
            int town; cin >> town;
            alien[town] = true;
            if(safe[town]) {
                safecnt--;
                safe[town] = false;
            }
            // bfs here?
            // starting point, add neighbors
            priority_queue<Q, vector<Q>, greater<Q>> q;
            Q start = Q(town, 0);
            vector<bool> visited(n+1, false);
            while(!q.empty()){
              Q current = q.top();
              q.pop();
            }
            cout << safecnt << '\n';
        }
        cout << "\n\n";
    }
}