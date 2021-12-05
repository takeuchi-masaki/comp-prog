#include <bits/stdc++.h>
using namespace std;


// point update, range sum
struct FenwickTree{
    vector<int> tree;
    int n;

    FenwickTree(vector<int> & values){
        this->n = values.size() + 1;
        tree = vector<int>(n);
        for(int i = 0; i < n - 1; i++){
            add(i, a[i]);
        }
    }

    int sum(int idx){
        int ret = 0;
        for(++idx; idx > 0; idx -= idx & -idx)
            ret += tree[idx];
        return ret;
    }

    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta){
        for(++idx; idx < n; idx += idx & -idx)
            tree[idx] += delta;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
}