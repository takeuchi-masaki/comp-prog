#include <bits/stdc++.h>
using namespace std;

int lower(int key, vector<int> & list){
    int ok = list.size(), bad = -1;
    while(ok - bad > 1){
        int mid = (ok + bad) / 2;
        if(list[mid] >= key) ok = mid;
        else bad = mid;
    }
    return ok;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    while(true){
        cin >> n;
        if(n == 0) break;
        vector<int> l1(n), l2(n), l1copy;
        for(int & i:l1) cin >> i;
        for(int & i:l2) cin >> i;
        l1copy = l1; 
        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());
        for(int i:l1copy){
            // int idx = lower_bound(l1.begin(), l1.end(), i) - l1.begin();
            int idx = lower(i, l1);
            cout << l2[idx] << '\n';
        }
        cout << '\n';
    }
}