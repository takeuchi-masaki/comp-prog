#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // can't mix ingredient a and b
    // find all possible combinations
    vector< pair<int,int> > v;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        v.push_back(make_pair(a,b));
    }
    // bit search
    int count = 0;
    for(int bit = 0; bit < (1<<n); bit++ ){
        vector<bool> use(n, false);
        for(int i = 0; i < n; i++){
            if(bit & (1<<i)) use[i] = true;
        }
        bool ok = true;
        for(pair<int,int> p:v){
            if(use[p.first] && use[p.second]) {
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        count++;
    }
    cout << count << endl;
}