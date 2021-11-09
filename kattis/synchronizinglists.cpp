#include <bits/stdc++.h>
using namespace std;

bool isOk(int mid, int target, vector<int> & list){
    if(list[mid] >= target) return true;
    return false;
}

int lower(int target, vector<int> & list){
    int ok = list.size(), bad = -1;
    while(ok - bad > 1){
        int mid = (ok + bad) / 2;
        if(isOk(mid, target, list)) ok = mid;
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
        vector<int> list1(n), list2(n), list1Copy;
        for(int & i : list1) cin >> i;
        for(int & i : list2) cin >> i;
        list1Copy = list1;
        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());
        for(int i:list1Copy){
            // int idx = lower_bound(list1.begin(), list1.end(), i) - list1.begin();
            int idx = lower(i, list1);
            cout << list2[idx] << '\n';
        }
        cout << '\n';
    }
}