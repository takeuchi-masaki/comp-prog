#include <bits/stdc++.h>
using namespace std;

struct Robot{
    int start, end;
    Robot(int c, int l){
        start = c - l;
        end = c + l;
    }
    bool operator < (Robot & r2) const {
        return this->end < r2.end;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<Robot> a;

    for(int i = 0; i < n; i++){
        int x, l; cin >> x >> l;
        a.push_back(Robot(x, l));
    }
    sort(a.begin(), a.end());

    int ans = 0, currEnd = -1e9;
    for(Robot r : a){
        if(r.start >= currEnd){
            ans++;
            currEnd = r.end;
        }
    }

    cout << ans << '\n';
}