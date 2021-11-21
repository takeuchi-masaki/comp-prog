#include <bits/stdc++.h>
using namespace std;

struct Sprinkler{
    double begin, end;
    bool operator < (const Sprinkler & s2){
        if(this->begin == s2.begin)
            return this->end > s2.end;
        return this->begin < s2.begin;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    double n, l, w;
    while(cin >> n >> l >> w){
        vector<Sprinkler> v, v2;
        double halfW = (double) w / 2;
        double halfWSq = halfW * halfW;
        for(int i = 0; i < n; i++){
            double pos, radius; cin >> pos >> radius;
            if(radius <= halfW) continue;
            double dist = sqrtl((radius * radius) - halfWSq);
            Sprinkler sp;
            sp.begin = max((double)0, pos - dist);
            sp.end = min(l, pos + dist);
            v.push_back(sp);
        }
        sort(v.begin(), v.end());
        
        v2.push_back(v[0]);
        for(int i = 1; i < v.size(); i++){
            if(v[i].end > v2.back().end){
                v2.push_back(v[i]);
            }
        }

        double prevEnd = 0, nextEnd = 0;
        int ans = 1;
        bool ok = true;
        for(int i = 0; i < v2.size(); i++){
            if(v2[i].begin <= prevEnd){
                nextEnd = max(nextEnd, v2[i].end);
                continue;
            }
            if(prevEnd == nextEnd){ // gap in sprinklers
                ok = false;
                break;
            }
            i--;
            ans++;
            prevEnd = nextEnd;
        }
        if(nextEnd < l) ok = false;
        cout << (ok ? ans : -1) << '\n';
    }
}