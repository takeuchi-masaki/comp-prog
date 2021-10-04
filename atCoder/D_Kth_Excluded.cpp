#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;

long long kthExcluded(long long k){
    long long low = -1, high = n;
    while(high - low > 1){
        long long mid = low + (high-low)/2;
        if(a[mid] < k){
            
        }
    }
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> n >> q;
    a = vector<long long> (n);
    for(long long &i:a) cin >> i;
    sort(a.begin(), a.end());
    for(int i = 0; i < q; i++){
        long long k; cin >> k;
        cout << kthExcluded(k) << endl;
    }
}