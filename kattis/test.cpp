#include <bits/stdc++.h>

void combine(std::vector<int>& a, int low, int mid, int high){
    std::vector<int> aux;
    int l = low, r = mid;
    while(l < mid || r < high){
        if(l == mid){
            aux.push_back(a[r++]);
            continue;
        }
        if(r == high){
            aux.push_back(a[l++]);
            continue;
        }
        if(a[l] <= a[r]){
            aux.push_back(a[l++]);
        } else {
            aux.push_back(a[r++]);
        }
    }
    for(int i = 0; i < aux.size(); i++){
        a[low + i] = aux[i];
    }
}

void mergesort(std::vector<int>& a, int low, int high){
    if(high <= low) return;
    int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    combine(a, low, mid, high);
}

int main(){
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);

    vector<int> a = {12, 11, 13, 5, 6, 7};
    
    mergesort(a, 0, a.size());

    for(int i : a) cout << i << ' ';
}