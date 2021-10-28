/*
ID: themasa1
TASK: holstein
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("holstein.in","r",stdin); freopen("holstein.out","w",stdout);
    int v; cin >> v;
    vector<int> req(v);
    for(int&i:req) cin >> i;
    int g; cin >> g; // feed types
    vector< vector<int> > feed(g, vector<int>(v));
    for(int i = 0; i < g; i++){
        for(int j = 0; j < v; j++){
            cin >> feed[i][j];
        }
    }
    int minScoops = 1e9;
    vector<int> scoopTypes;
    for(int bit = 0; bit < (1<<g); bit++){
        vector<int> curr = req;
        int scoopCount = 0;
        for(int i = 0; i < g; i++){
            if(bit>>i&1){
                scoopCount++;
                for(int vit = 0; vit < v; vit++){
                    curr[vit]-=feed[i][vit];
                }
            }
        }
        bool bad = false;
        for(int i:curr) {
            if(i > 0){
                bad = true;
                break;
            }
        }
        if(bad) continue;
        if(scoopCount < minScoops){
            minScoops = scoopCount;
            scoopTypes.clear();
            for(int i = 0; i < g; i++){
                if(bit>>i&1) scoopTypes.push_back(i+1);
            }
        }
    }
    cout << minScoops << ' ';
    for(int i = 0; i < scoopTypes.size()-1; i++){
        cout << scoopTypes[i] << ' ';
    }
    cout << scoopTypes[scoopTypes.size()-1] << '\n';
    return 0;
}