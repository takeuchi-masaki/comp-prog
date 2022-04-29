#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> mps(2), sec(2), rest(2), dist(2);
    for(int i = 0; i < 2; i++){
        cin >> sec[i] >> mps[i] >> rest[i];
    }
    
    int endTime;
    cin >> endTime;
    for(int i = 0; i < 2; i++){
        int cycle = sec[i] + rest[i];
        int fullCycles = endTime / cycle;
        dist[i] += fullCycles * mps[i] * sec[i];
        int remain = endTime % cycle;
        dist[i] += min(remain, sec[i]) * mps[i];
    }

    if(dist[0] == dist[1]){
        cout << "Draw\n";
    } else if(dist[0] > dist[1]){
        cout << "Takahashi\n";
    } else {
        cout << "Aoki\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    solve();
}