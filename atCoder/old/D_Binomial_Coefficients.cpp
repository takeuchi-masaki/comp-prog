#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    sort(a.begin(), a.end());

    int target = a[n - 1] / 2;
    auto it = lower_bound(a.begin(), a.end() - 1, target);
    if(it == a.end() - 1) it--;
    if(it != a.begin()){
        auto it2 = it - 1;
        int idx1 = it - a.begin();
        int idx2 = it2 - a.begin();
        if(abs(*it2 - target) < abs(*it - target)){
            cout << a[n - 1] << ' ' << *it2 << '\n';
            return 0;
        }
    }
    cout << a[n - 1] << ' ' << *it << '\n';
}