#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector< vector<int> > runners(n, vector<int>(m));
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<> > pq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> runners[i][j];
            pq.push(make_pair(runners[i][j], i));
        }
    }
    for(int i = 0; i < n; i++){
        sort(runners[i].begin(), runners[i].end());
    }
    
    vector< vector<int> > ans(n, vector<int>(m));
    vector<int> cntBack(105);
    for(int j = 0; j < m; j++){
        pair<int,int> next = pq.top();
        pq.pop();
        // cout << next.first << ' ' << next.second << '\n';
        for(int i = 0; i < n; i++){
            if(i==next.second){
                ans[i][j] = next.first;
            } else {
                ans[i][j] = runners[i][m-1-cntBack[i]];
                cntBack[i]++;
            }
        }
    }
    
    // for(int j = 0; j < m; j++){
    //     int curr = 1e9+7, currIndex;
    //     for(int i = 0; i < n; i++){
    //         if(runners[i][cntUsed[i]] < curr){
    //             curr = runners[i][cntUsed[i]];
    //             currIndex = i;
    //         }
    //     }
    //     // cout << curr << ' ' << currIndex << '\n';
        // for(int i = 0; i < n; i++){
        //     if(i==currIndex){
        //         // cout << i << ' ' << runners[i][cntUsed[i]] << '\n';
        //         ans[i][j] = runners[i][cntUsed[i]];
        //         cntUsed[i]++;
        //     } else {
        //         // int back = cntUsed[i];
        //         // cout << "back " << i << ' ' << runners[i][m-1-cntBack[i]] << '\n';
        //         // ans[i][j] = -1;
        //         ans[i][j] = runners[i][m-1-cntBack[i]];
        //         cntBack[i]++;
        //     }
        // }
    // }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}