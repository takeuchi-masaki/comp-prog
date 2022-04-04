#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector< vector< pair<int, int> > > testimonies(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        for(int j = 0; j < a; j++){
            int x, y; cin >> x >> y;
            x--;
            testimonies[i].push_back(make_pair(x, y));
        }
    }
    int honest_max = 0;
    for(int bit = 0; bit < (1<<n); bit++){
        vector<bool> honest(n, false);
        int curr = 0;
        for(int person = 0; person < n; person++){
            if( (bit >> person) &1) {
                honest[person] = true;
                curr++;
            }
        }
        bool ok = true;
        for(int i = 0; i < n && ok; i++){
            if(!honest[i]) continue;
            for(pair<int, int> p:testimonies[i]){
                if(honest[p.first] != p.second) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) honest_max = max(honest_max, curr);
    }
    cout << honest_max << endl;
}