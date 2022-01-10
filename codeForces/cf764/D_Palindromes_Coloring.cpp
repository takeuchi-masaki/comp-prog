#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    string s; 
    cin >> n >> k >> s;
    vector<int> a(26);
    for(char c : s){
        a[c - 'a']++;
    }
    map<int,int> evenFrq;
    int oddFrq = 0;
    for(int i : a){
        if(i & 1){
            oddFrq++;
            i--;
        }
        if(i == 0) continue;
        evenFrq[i]++;
    }

    int ans = 1;
    int l = 1, r = n + 1;
    while(r - l > 1){
        int m = (l + r) / 2;
        bool ok = true, odd = m&1;
        map<int,int> e = evenFrq;
        int o = oddFrq;
        for(int i = 0; i < k && ok; i++){
            int curr = 0;
            if(odd){
                if(o == 0){
                    if(e.empty()){
                        ok = false;
                        break;
                    }
                    o += 2;
                    pair<int,int> p = *e.begin();
                    e[p.first]--;
                    if(p.first > 2){
                        e[p.first - 2]++;
                    }
                    if(e[p.first] == 0){
                        e.erase(e.begin());
                    } else {
                        e[p.first]--;
                    }
                }
                o--;
            }
            while(curr < m){
                if(e.empty()){
                    ok = false;
                    break;
                }
                int diff = m - curr;
                pair<int,int> p = *e.begin();
                e[p.first]--;
                curr += min(p.first, diff);
                p.first -= diff;
                if(p.first > 0){
                    e[p.first]++;
                }
                if(e.begin()->second == 0){
                    e.erase(e.begin());
                }
            }
            if(curr < m){
                ok = false;
                break;
            }
        }

        if(ok){
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}