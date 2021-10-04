#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

void solve(){
    int k, w, h; cin >> k >> w >> h;
    vector< vector<int> > time_min(h, vector<int>(w, INF)), difficulty(h, vector<int>(w, 0));
    unordered_map<char, int> power;
    for(int i = 0; i < k; i++){
        char c; int weight;
        cin >> c >> weight;
        power.insert(make_pair(c, weight));
    }
    int startH, startW;
    for(int row = 0; row < h; row++){
        for(int col = 0; col < w; col++){
            char c; cin >> c;
            if(c == 'E'){
                startH = row, startW = col;
                time_min[startH][startW] = 0;
            } else {
                difficulty[row][col] = power[c];
            }
        }
    }
    int minTime = INF;
    priority_queue< pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > > q;
    pair< int, pair<int, int> > start = make_pair(0, make_pair(startH, startW));
    q.push(start);
    while(q.size()){
        pair< int, pair<int, int> > next = q.top(); q.pop();
        pair<int, int> coord = next.second;
        if (coord.first == 0 || coord.second == h - 1 || coord.first == 0 || coord.second == w - 1) {
            cout << next.first << endl;
            break;
        }
        pair<int, int> directions[] = {
            make_pair(coord.first-1, coord.second),
            make_pair(coord.first+1, coord.second),
            make_pair(coord.first, coord.second-1),
            make_pair(coord.first, coord.second+1)
        };
        for(pair<int,int> p : directions){
            if(p.first < 0 || p.first >= h
            || p.second < 0 || p.second >= w){
                continue;
            }
            if(time_min[p.first][p.second] < INF){
                continue;
            }
            time_min[p.first][p.second] = next.first + difficulty[p.first][p.second];
            q.push( make_pair(next.first + difficulty[p.first][p.second], p) );
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("Escape.in","r",stdin); freopen("out.txt","w",stdout);
    // clock_t start, end;
    // start = clock();

    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }

    // end = clock();

    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cout << "Time taken by program is : " << fixed 
    //      << time_taken << setprecision(5);
    // cout << " sec " << endl;
}