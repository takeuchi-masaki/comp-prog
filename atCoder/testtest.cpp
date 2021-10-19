#include <bits/stdc++.h>
using namespace std;

int n, honest_max;
vector< vector< pair<int, int> > > testimonies;

void dfs(vector<bool>& honest){
    for(bool b:honest){
        cout << b << ' ';
    }
    cout << '\n';
    if(honest.size() < n){
        honest.push_back(true);
        dfs(honest);
        honest.pop_back();
        honest.push_back(false);
        dfs(honest);
        honest.pop_back();
        return;
    }
    int curr = 0;
    for(bool b:honest) if(b) curr++;
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
    honest_max = 0;
    vector<bool> honest;
    dfs(honest);
    cout << honest_max << endl;
}