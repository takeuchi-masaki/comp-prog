#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e10;
int ROW, COL;
vector<vector<int>> grid;

class State{
    public:
    int I, J;
    long long val;
    State(int currI, int currJ, long long currVal){
        this->I = currI;
        this->J = currJ;
        this->val = currVal;
    }
    bool operator<(const State &o) const {
        return this->val > o.val;
    }
};

vector<vector<long long>> dijk(int startI, int startJ){
    vector< vector<long long> > dist(ROW, vector<long long>(COL, INF));
    dist[startI][startJ] = 0;
    priority_queue<State> pq;
    pq.push(State(startI, startJ, 0));
    while(!pq.empty()){
        State curr = pq.top(); pq.pop();
        vector<pair<int, int>> next = {
            {curr.I-1, curr.J},
            {curr.I+1, curr.J},
            {curr.I, curr.J-1},
            {curr.I, curr.J+1}
        };
        for(auto p:next){
            if(p.first < 0
            || p.second < 0
            || p.first >= ROW
            || p.second >= COL) continue;
            long long newDist = curr.val+grid[p.first][p.second];
            if(newDist >= dist[p.first][p.second]) continue;
            dist[p.first][p.second] = newDist;
            pq.push(State(p.first, p.second, newDist));
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> ROW >> COL;
    grid = vector<vector<int>>(ROW, vector<int>(COL));
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            cin >> grid[i][j];
        }
    }

    long long ans = INF;
    vector<vector<long long>> from_bottomleft = dijk(ROW-1, 0),
    from_bottomright = dijk(ROW-1, COL-1),
    from_topright = dijk(0, COL-1);

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            long long curr = from_bottomleft[i][j];
            curr += from_bottomright[i][j]-grid[i][j];
            curr += from_topright[i][j]-grid[i][j];
            ans = min(ans, curr);
        }
    }
    cout << ans << '\n';
}