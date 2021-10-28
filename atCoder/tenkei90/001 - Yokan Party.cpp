#include <bits/stdc++.h>
using namespace std;

int n, l, k;
vector<int> a;

bool ok(int num){
    int prev = 0, cuts = 0;
    for(int i = 0; i < n; i++){
        if(a[i]-prev >= num){
            prev = a[i];
            cuts++;
        }
    }
    if(l-prev >= num){
        cuts++;
    }
    return cuts >= k+1;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> l >> k;
    a = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = -1, r = 1e9+1;
    while(r-l>1){
        int mid = l + (r-l)/2;
        if( ok(mid) ){
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}