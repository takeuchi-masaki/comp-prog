/*
ID: themasa1
TASK: milk3
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
int capacity[3];
bool states[21][21][21];

int main() {
    freopen("milk3.in","r",stdin); freopen("milk3.out","w",stdout);
    for(int i = 0; i < 3; i++){
        cin >> capacity[i];
    }
    deque< vector<int> > dq;
    vector<int> start(3);
    start[2] = capacity[2];
    dq.push_back(start);
    states[0][0][capacity[2]] = true;
    while(dq.size()){
        vector<int> curr = dq.front();
        dq.pop_front();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i==j) continue;
                if(!curr[i]) continue;
                vector<int> next(3);
                next[i] = max(0, curr[i]-(capacity[j]-curr[j]) );
                next[j] = min(capacity[j], curr[i]+curr[j]);
                int k = 3-i-j;
                next[k] = curr[k];
                if( !states[ next[0] ][ next[1] ][ next[2] ] ){
                    states[ next[0] ][ next[1] ][ next[2] ] = true;
                    dq.push_back(next);
                }
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            if(states[0][j][i]){
                ans.push_back(i);
                break;
            }
        }
    }
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++){
        cout << ' ' << ans[i];
    }
    cout << '\n';
    return 0;
}