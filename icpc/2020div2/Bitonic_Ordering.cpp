#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<long long> bit;
    int n;
    FenwickTree(int n) : bit(n, 0), n(n) {}
    long long sum(int r) {
        long long ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    long long sum(int l, int r) { return sum(r) - sum(l - 1); }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    FenwickTree ft(n);
    for(int i = 0; i < n; i++) ft.add(i, 1);

    long long inv = 0;
    for(auto [val, idx] : a){
        long long before = ft.sum(idx - 1);
        long long after = ft.sum(idx + 1, n - 1);
        inv += min(before, after);
        ft.add(idx, -1);
    }
    cout << inv << '\n';
}