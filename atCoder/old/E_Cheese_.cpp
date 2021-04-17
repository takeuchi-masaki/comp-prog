#include <bits/stdc++.h>
using namespace std;

struct triple{
    int first, second, dist;
    triple(pair<int,int> p, int distance){
        first = p.first;
        second = p.second;
        dist = distance;
    }
    triple(int f, int s, int distance){
        first = f;
        second = s;
        dist = distance;
    }
    triple(){
        first = -1;
        second = -1;
        dist = -1;
    }
};

void solve(){
    int h, w, n;
    cin >> h >> w >> n;
    triple start;
    vector<string> grid(h);
    for(int i = 0; i < h; i++){
        cin >> grid[i];
        for(int j = 0; j < w; j++){
            if(grid[i][j]=='S') {
                grid[i][j]='.';
                start = triple(i,j,0);
            }
        }
    }
    for(int i = 0; i < n; i++){
        queue<triple> q;
        q.push(start);
        vector<vector<bool>> visited(h, vector<bool>(w,false));
        visited[start.first][start.second]=true;
        while(!q.empty()){
            triple next = q.front(); q.pop();
            // cout << next.first << " " << next.second << " " << next.dist << "\n";
            pair<int,int> checkNext[4] = {
                    {next.first-1, next.second},
                    {next.first+1, next.second},
                    {next.first, next.second-1},
                    {next.first, next.second+1}
            };
            bool found = false;
            for(pair<int,int> check:checkNext){
                if(check.first>=0 && check.second>=0
                   && check.first<h && check.second<w
                   && grid[check.first][check.second] != 'X'){
                    if( !visited[check.first][check.second] ){
                        visited[check.first][check.second]=true;
                        if(grid[check.first][check.second] == i+'1'){
                            // cout << check.first << " " << check.second << " " << (char)(i+'1') << " " << (next.dist+1) << '\n';
                            start = triple(check, next.dist+1);
                            found = true;
                            break;
                        }
                        q.push( triple(check, next.dist+1) );
                    }
                }
            }
            if(found) break;
        }
    }
    cout << start.dist << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}