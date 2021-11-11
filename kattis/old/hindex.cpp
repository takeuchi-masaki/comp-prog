#include <bits/stdc++.h>
using namespace std;

bool checkHIndex(int h, vector<int> & a){
    int diff = a.size() - h;
    for(int i = 0; i < h; i++){
        if(a[i + diff] < h) return false;
    }
    return true;
}

int maxH_Index(vector<int> & a){
    int ok = 0, bad = a.size()+1;
    while(bad - ok > 1){
        int mid = (ok + bad) / 2;
        if(checkHIndex(mid, a)) ok = mid;
        else bad = mid;
    }
    return ok;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    sort(a.begin(), a.end());
    cout << maxH_Index(a) << '\n';
}